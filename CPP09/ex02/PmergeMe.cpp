/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/15 23:16:37 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<unsigned int> js_insert(std::vector<unsigned int> &sorted, unsigned int val, unsigned int jacobshtal_pos)
{
	jacobshtal_pos = std::min(jacobshtal_pos, static_cast<unsigned int>(sorted.size()));
	int low = jacobshtal_pos;
	int high = sorted.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (sorted[mid] < val)
		{
			low = mid + 1;
		}
		else 
			high = mid;
	}
	sorted.insert(sorted.begin() + low, val);
	return sorted;
}

std::vector<unsigned int> merge_ins(std::vector <unsigned int> &min, std::vector <unsigned int> &max, std::vector <unsigned int> &jacobshtal_num)
{
	std::vector<unsigned int> res = min;
	for (size_t i = 0; i < max.size(); ++i)
	{
		int index = std::min(i, jacobshtal_num.size() - 1);
		res = js_insert(res, max[i], jacobshtal_num[index]);
	}
	return res;
}

std::vector<unsigned int> generate_js (unsigned int x)
{
	std::vector<unsigned int> jacobshtal_n;
	jacobshtal_n.push_back(0);
	jacobshtal_n.push_back(1);
	unsigned int i = 2;
	while (i <= x)
	{
		jacobshtal_n.push_back(jacobshtal_n[i - 1] + 2 * jacobshtal_n[i - 2]);
		++i;
	}
	return (jacobshtal_n);
}

std::vector<unsigned int>  merge_vect (std::vector<unsigned int> &min, std::vector<unsigned int> &max)
{
	std::vector<unsigned int> vct;
	size_t k = 0;
	size_t l = 0;
	while (k < min.size() && l < max.size())
	{
		if (min[k] <= max[l])
		{
			vct.push_back(min[k]);
			k++;
		}
		else 
		{
			vct.push_back(max[l]);
			l++;
		}
	}
	while (k < min.size())
	{
		vct.push_back(min[k]);
		k++;
	}
	while (l < max.size())
	{
		vct.push_back(max[l]);
		l++;
	}
	return (vct);
}

std::vector<unsigned int>  fj_sort (std::vector<unsigned int> &vec)
{
	if (vec.size() < 2)
		return vec;
	int mid = vec.size() / 2;
	std::vector<unsigned int> minim(vec.begin(), vec.begin() + mid);
	std::vector<unsigned int> maxim(vec.begin() + mid, vec.end());
	minim = fj_sort(minim);
	maxim = fj_sort(maxim);
	return (merge_vect(minim, maxim));
}

void	MergeInsertVec(std::vector<std::pair<unsigned int, unsigned int> >&container, const bool &odd,const unsigned int &tmp, struct timeval start)
{
	std::vector <unsigned int> low, high;
	struct timeval end;
	long		sec, mic, timeTaken;

	size_t	i = 0;
	while (i < container.size())
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
		low.push_back(container[i].first);
		high.push_back(container[i].second);
		i++;
	}
	if (odd) {
        low.push_back(tmp);
    }
	low = fj_sort(low);
	high = fj_sort(high);
	std::vector<unsigned int> jacobshtal_seq = generate_js(high.size());
	std::vector <unsigned int> sorted = merge_ins(low, high, jacobshtal_seq);
	std::cout << "After vector: ";
	if ( sorted.size() < 20 ) {
        for ( size_t i = 0; i < sorted.size(); i++ )
            std::cout << sorted[i] << " ";
    } else {
        for ( int i = 0; i < 20; i++ )
            std::cout << sorted[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	mic = end.tv_usec - start.tv_usec;
	timeTaken = sec * 1000000 + mic;
	std::cout << "Time to sort a range of " << sorted.size() << " elements with std::vector: " << timeTaken << " microseconds" << std::endl;
}
/* DEQUE */
std::deque<unsigned int> js_insert_deq(std::deque<unsigned int> &sorted, unsigned int val, unsigned int jacobshtal_pos)
{
	jacobshtal_pos = std::min(jacobshtal_pos, static_cast<unsigned int>(sorted.size()));
	int low = jacobshtal_pos;
	int high = sorted.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (sorted[mid] < val)
		{
			low = mid + 1;
		}
		else 
			high = mid;
	}
	sorted.insert(sorted.begin() + low, val);
	return sorted;
}

std::deque<unsigned int> merge_ins_deq (std::deque <unsigned int> &min, std::deque <unsigned int> &max, std::vector <unsigned int> &jacobshtal_num)
{
	std::deque<unsigned int> res = min;
	for (size_t i = 0; i < max.size(); ++i)
	{
		int index = std::min(i, jacobshtal_num.size() - 1);
		res = js_insert_deq(res, max[i], jacobshtal_num[index]);
	}
	return res;
}

std::deque<unsigned int>  merge_deq (std::deque<unsigned int> &min, std::deque<unsigned int> &max)
{
	std::deque<unsigned int> dqe;
	size_t k = 0;
	size_t l = 0;
	while (k < min.size() && l < max.size())
	{
		if (min[k] <= max[l])
		{
			dqe.push_back(min[k]);
			k++;
		}
		else 
		{
			dqe.push_back(max[l]);
			l++;
		}
	}
	while (k < min.size())
	{
		dqe.push_back(min[k]);
		k++;
	}
	while (l < max.size())
	{
		dqe.push_back(max[l]);
		l++;
	}
	return (dqe);
}

std::deque<unsigned int>  fj_sort_deq (std::deque<unsigned int> &deq)
{
	if (deq.size() < 2)
		return deq;
	int mid = deq.size() / 2;
	std::deque<unsigned int> minim(deq.begin(), deq.begin() + mid);
	std::deque<unsigned int> maxim(deq.begin() + mid, deq.end());
	minim = fj_sort_deq(minim);
	maxim = fj_sort_deq(maxim);
	return (merge_deq(minim, maxim));
}



void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp, struct timeval start ) {
    std::deque<unsigned int>   low, high;
    struct timeval  end;
    long            sec, mic, timeTaken;

    gettimeofday( &start, NULL );
	size_t i = 0;
	while (i < container.size())
	{
		if ( container[i].first > container[i].second )
            std::swap( container[i].first, container[i].second );
		low.push_back( container[i].first );
		high.push_back( container[i].second );
		i++;
	}
    if (odd) {
        low.push_back(tmp);
    }
	low = fj_sort_deq(low);
	high = fj_sort_deq(high);
	std::vector<unsigned int> jacobshtal_seq = generate_js(high.size());
	std::deque <unsigned int> sorted = merge_ins_deq(low, high, jacobshtal_seq);


    std::cout << "After deque : ";
    if ( sorted.size() < 20 ) {
        for ( size_t i = 0; i < sorted.size(); i++ )
            std::cout << sorted[i] << " ";
    } else {
        for ( int i = 0; i < 20; i++ )
            std::cout << sorted[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
    gettimeofday( &end, NULL );
    sec = end.tv_sec - start.tv_sec;
    mic = end.tv_usec - start.tv_usec;
    timeTaken = sec * 1000000 + mic;
    std::cout << "Time to sort a range of " << sorted.size() << " elements with std::deque : " << timeTaken << " microseconds" << std::endl;
}