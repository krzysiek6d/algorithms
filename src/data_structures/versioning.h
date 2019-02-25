//
// Created by krzysiek on 2/25/19.
//

#ifndef ALGORITHMS_VERSIONING_H
#define ALGORITHMS_VERSIONING_H

namespace alg
{
    namespace detail
    {
        template <typename K, typename T>
        struct Element
        {
            K key;
            T elem;
        };
    }
    template <typename K, typename T>
    struct VersionedDB
    {
        void add(const K& key, const T& element)
        {
            data.push_back(detail::Element<K,T>{key, element});
        }

        int makeSnapshot()
        {
            return data.size();
        }

        const T& get(const K& key)
        {
            return get(key, data.size());
        }

        const T& get(K key, int snapshotId)
        {
            for(int i = snapshotId - 1; i>=0 && snapshotId <= (int)data.size() ; i--)
            {
                if(data[i].key == key)
                    return data[i].elem;
            }
            throw std::runtime_error("cant find element");
        }
        std::vector<detail::Element<K,T>> data;
    };
}


#endif //ALGORITHMS_VERSIONING_H
