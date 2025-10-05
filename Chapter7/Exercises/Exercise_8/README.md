**This is another way to re-arrange the age_vector to match the names_vector after sorting the names**  
**without the need to create and copy more vectors**  
**This is a manual way to short 2 vectors, to learn how sorting works**

---

**1.** Let's say we have a vector of names and a vector of ages:

```cpp
std::vector<std::string> names;
std::vector<double> ages;
```

**2.** We add some names into the `names vector` and some ages into the `ages vector`  
and each age of each person is in the same index in each vector:

```cpp
for(int i = 0; i < names.size(); i++) // assuming the ages vector has the same size
{
    std::cout << names[i] << '\t' << ages[i] << std::endl;
}
```

**3.** Now is the time for the sort and order method

```cpp
void sort_and_order(std::vector<std::string>& names, std::vector<double>& ages)
{
    std::string bigger = "";
    int bigger_age = 0;

    for(int i = 0; i < names.size() - 1; i++)
    {
        for(int j = i + 1; j < names.size(); j++)
        {
            if(names[i] > names[j])
            {
                bigger = names[i];
                names[i] = names[j];
                names[j] = bigger;
                
                bigger_age = ages[i];
                ages[i] = ages[j];
                ages[j] = bigger_age;
            }
        }
    }
}
```

**This guarantees that every age stays associated with the correct name when the list is sorted.**