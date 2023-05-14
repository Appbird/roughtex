#ifndef STRING_READER_INCLUDED
#define STRING_READER_INCLUDED
#include <string>
/**
 * @brief 一文字ずつ空白を読み飛ばさず読むリーダー。先読みも逆戻りも可能。
 * 
 */
class string_reader{
    private:
        std::string_view buffer;
        int max;
        int pointer = 0;
    public:
        string_reader(const std::string_view& _buffer): 
            buffer(_buffer)
        {
            max = buffer.size();
        }
        /** pointerが終点にいないことを示す。*/
        bool not_at_the_end(){
            return pointer != max;
        }
        /** pointerが始点にいないことを示す。 */
        bool not_at_the_first(){
            return pointer != 0;
        }
        /** 一文字読む。pointerは進まない。*/
        char peek(){
            return buffer.at(pointer);
        }
        /** 一文字読む。pointerが一文字分進む。 */
        char get(){
            return buffer.at(pointer++);
        }
        /** 一文字読み戻す。 pointerが一文字引き戻される。*/
        char back(){
            return buffer.at(--pointer);
        }

        string_reader& operator>>(char& receiver){
            receiver = get();
            return *this;
        }
};
#endif