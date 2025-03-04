#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace Random 
{

    // returns a seeded Mersenne Twister
    inline std::mt19937 generate()
    {
        std::random_device rd{};

        // seed sequence with clock and 7 random numbers from random_device
        std::seed_seq ss {
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd() 
        };

        return std::mt19937 { ss };
    }

    // global Mersenne Twister object 
    inline std::mt19937 mt { generate() };

    // return a number between [min, max] inclusive
    inline int get(int min, int max)
    {
        return std::uniform_int_distribution<>{min, max}(mt);
    }

    
    template <typename T>
    T get(T min, T max)
    {
        return std::uniform_int_distribution<T>{min, max}(mt);
    }

    
	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}



}


#endif