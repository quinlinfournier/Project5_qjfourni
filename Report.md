# Project 5 Report

Answer the following prompts directly in this file:
* Information about your dataset. You will be assigned a different grader for this project.
* Which Open Addressing hash tables change size during the program? Why?
* Create graphs for the number of collisions for inserting your dataset into all 20 hash tables.
  * Clearly label the graph titles and axes.
  * Set up the graph in a way that makes the most sense to you. Here are some options I have seen before:
    * Using a line graph to track the *individual* collision counts as each insertion is made. High-valued blips happen in open addressing when rehashes occur.
    * Using a line graph to track the *cumulative* collision count as each insertion is made. Vertical jumps happen in open addressing when rehashes occur.
    * Using a line graph to track the *average* number of collisions per insertion, where each hash table has one value and you can see the trends as the initial table size grows.
* Using the graphs, analyze why the collision counts are different for the different size hash tables. Use what you know about your keys and the hash tables to justify why the collision counts make sense.
* Determine which global function works best as the key for your dataset objects based on the collision counts.
* Draw conclusions about which hash collision detection method works best on your dataset (separate chaining or open addressing).

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**



The 8 attributes in this project are the National Database Number(ndn), Common name, Species, State(that they were sighted in), date sighted, longitude, Latitude, Length. I got the data from https://www.fisheries.noaa.gov/national/marine-life-distress/national-stranding-database-public-access?utm_source=chatgpt.com. After looking around I thought that the large whale data was interesting data also I think that sea creatures are cool. The data is in order of date collected from oldest to newest from the years of 2005-2015. In order to check to see if the function was working correctly I used the command f to find something and searched up the term I wanted to count and it matched the number that was being output by my code. I chose the number of killer whales there were in the data set so created a function that would display the answer.

All of the hash tables with a length that is less than double the length of the original data set. The reason for this is that is what is looked for to call the rehash function.

  * ![Graph 1](output(7).png)
  * ![Graph 2](output(6).png)
  * ![Graph 3](output(5).png)
  * ![Graph 4](output(4).png)
The collision graphs show that smaller table sizes consistently result in more collisions. This is expected behavior, as:
A smaller number of slots means more hash key values will map to the same index, especially as the load factor increases.
Open addressing suffers more in smaller tables due to clustering and limited probing room.
In contrast, larger tables allow keys to be distributed more widely, reducing collisions significantly. This is especially visible in Open Addressing, where average collisions per insert dropped to near zero once the table size exceeded twice the number of elements.
Additionally, rehashing in open addressing introduces visible spikes in individual collision graphs. These occur because every insert during rehashing must probe a newly enlarged table
getNdnSpeciesKey is a better choice as it is more diverse which causes a better distribution and this leads to fewer collisions 
The best combination for my data set is OpenAddressing with a data set over the size of 2500. This combination had the lowest total collisions and is the most memory efficient 
