#include "nd_mem_manager.h"



void* operator new(size_t need_size)
{
	if (m_memory == 0)
	{
		atexit(nd_mgr_exit);
		m_memory = (size_t)malloc(m_memory_limit_bytes);
		m_memory_end = 0;
		if (m_memory == 0)
		{
			exit(0xBDBDBDBD);
		}
		float* memory = (float*)m_memory;
		float* memory_end = memory + m_memory_limit_bytes/sizeof(mark_free);
		for (; memory < memory_end - 1;)
		{
			*memory = mark_free;
			memory++;
		}
		*memory = mark_portion;
	}

	float* memory = (float*)m_memory;
	float* memory_end = memory + m_memory_limit_bytes / sizeof(mark_free);
	float* free_mem_start = 0;
	float* free_mem_end = 0;
	for (; memory < memory_end; memory++)
	{
		if (*memory == mark_free && free_mem_start == 0)
		{
			free_mem_start = memory;
		}
		if(*memory == mark_portion && free_mem_start != 0)
		{
			free_mem_end = memory++;
			break;
		}
	}
	if (free_mem_end == 0)
	{
		free_mem_end = memory_end;
	}
	size_t avaliable_bytes = (free_mem_end - free_mem_start);
	if (avaliable_bytes >= need_size)
	{
		auto mark_free_pos = free_mem_start + need_size/sizeof(mark_free) + 1;
		*mark_free_pos = mark_portion;
		m_memory_end += (mark_free_pos - free_mem_start) * sizeof(mark_free);
		return (void*)free_mem_start;
	}
	else
	{
		float* memory = (float*)(m_memory + m_memory_end * sizeof(mark_free));
		size_t mem_pos = (size_t)m_memory_end * sizeof(mark_free) + need_size;
		if (mem_pos > (m_memory_limit_bytes - avaliable_bytes))
		{
			cout << "Произошло переполнение буфера 200Мб, в соотвествии с лицензионным соглашением" << endl;
			cout << "отчет об ошибке был отправлен на сервер РУП АиС, текущий рейтинг программы Х=Y" << endl;
			cout << "Приносим извинения за доставленные неудобства, в скоре с вами свяжется менеджер" << endl;
			cout << "поддержки для урегулирования данного инцедента." << endl;
			cout << "Спасибо что выбрали нашу компанию." << endl;
			exit(126);
		}
		m_memory_end += need_size / sizeof(mark_free) + 1;
		float* memory_mark_end = (float*)m_memory + m_memory_end;
		*memory_mark_end = mark_portion;
		return memory;
	}
}

void nd_mgr_exit()
{
	free((void*)m_memory);
}

void operator delete(void* mem)
{
	float* memory = (float*)mem;
	for (; ; memory++)
	{
		if (*memory != mark_portion)
		{
			*memory = mark_free;
		}
		else
		{
			break;
		}
	}
}
