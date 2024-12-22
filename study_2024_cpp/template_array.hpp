#pragma once

template<class T>
class MyArray
{
    public:
    MyArray(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        //T如果是Maker类，则需要初始化，否则会报错
        this->arr = new T[this->capacity];
    }
    MyArray(const MyArray& arr)
    {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->arr = new T[this->capacity];
        for(int i=0; i<this->size; i++)
        {
            this->arr[i] = arr.arr[i];
        }
    }
    MyArray& operator=(const MyArray& arr)
    {
        if(this!= &arr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->arr = new T[this->capacity];
        this->capacity = arr.capacity;
        this->size = arr.size;

        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = arr.arr[i];
        }
        return *this;
    }
    T &operator[](int index)
    {
        return this->arr[index];
    }

    //尾插
    void push_back(const T& value)
    {
        if(this->size == this->capacity)
        {
            return;
        }
        this->arr[this->size] = value;
        this->size++;
    }

    //尾删
    void pop_back()
    {
        if(this->size == 0)
        {
            return;
        }
        this->size--;
    }

    ~MyArray()
    {
        if(this->arr!= nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }

    }

    int get_size() const
    {
        return this->size;
    }
    private:
        T* arr;
        int size;
        int capacity;
};
