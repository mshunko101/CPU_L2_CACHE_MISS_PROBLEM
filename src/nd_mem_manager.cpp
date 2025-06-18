#include "nd_mem_manager.h"



void* operator new(size_t need_size)
{
    cout << "New operator overloading " << endl;

    if (m_memory == 0)
    {
        std::atexit(nd_mgr_exit);
        m_memory = (size_t)malloc(m_mem_limit);
        m_mem_state_length = m_mem_limit / 32;
        m_mem_state = (mem_block*)malloc(sizeof(mem_block) * m_mem_state_length);
        memset(m_mem_state, 0, sizeof(mem_block) * m_mem_state_length);
        memset((void*)m_memory, 0, m_mem_limit);
    }
    size_t guard_need_size = need_size;
    int i = 0;
    for (; i < m_mem_state_end; i++)
    {
        if (m_mem_state[i].m_free)
        {
            break;
        }
    }
    if (i < m_mem_state_end)
    {
        mem_block& mem = m_mem_state[i];
        if (guard_need_size == mem.m_size)
        {
            mem.m_free = false;
            return mem.position();
        }
        else if (guard_need_size < mem.m_size)
        {
            auto divided = mem.devide(guard_need_size);
            memmove(m_mem_state + i + 1, m_mem_state + i, sizeof(mem_block) * (m_mem_state_end - i));
            m_mem_state[i] = divided;
            return divided.position();
        }
        else
        {
            goto bad_code_hint;
        }
    }
    else
    {
    bad_code_hint:
        size_t mem_limit = m_free_pos_start + guard_need_size;
        if (mem_limit >= m_mem_limit)
        {
            cout << "Произошло переполнение буфера 200Мб, в соотвествии с лицензионным соглашением" << endl;
            cout << "отчет об ошибке был отправлен на сервер РУП АиС, текущий рейтинг программы Х=Y" << endl;
            cout << "Приносим извинения за доставленные неудобства, в скоре с вами свяжется менеджер" << endl;
            cout << "поддержки для урегулирования данного инцедента." << endl;
            cout << "Спасибо что выбрали нашу компанию." << endl;
            throw 0xBDBDBDBD;
        }
        auto mem_start = m_memory + m_free_pos_start;
        mem_block mem(mem_start, guard_need_size);
        auto ret_value = mem.position();
        m_mem_state[m_mem_state_end++] = mem;
        m_free_pos_start += guard_need_size;
        return ret_value;
    }
}

void nd_mgr_exit()
{
    free((void*)m_memory);
    free(m_mem_state);
}

void operator delete(void* mem)
{
    cout << "Delete operator overloading " << endl;
    //instance.free(p);
    for (int i = 0; i < m_mem_state_end; i++)
    {
        if (m_mem_state[i].position() == mem)
        {
            m_mem_state[i].m_free = true;
            break;
        }
    }

    if (m_merge_counter % 2 == 0)
    {
        int i = 0;
        for (; i < m_mem_state_end - 1; i++)
        {
            if (m_mem_state[i].m_free == true && m_mem_state[i + 1].m_free == true)
            {
                break;
            }
        }
        if (i < m_mem_state_end - 1)
        {
            mem_block merged((size_t)m_mem_state[i].position(), m_mem_state[i].m_size + m_mem_state[i + 1].m_size);
            merged.m_free = true;
            memcpy(m_mem_state + i, m_mem_state + i + 1, sizeof(mem_block) * m_mem_state_end - (i + 1));
            m_mem_state[i] = merged;
            m_mem_state_end--;
        }
    }

    m_merge_counter++;
}

