                       MAXIMUM IPO PROFIT   
Description: Suppose one company,Chandragiri Hills wants to start its IPO soon. In order to sell a good price of its shares to B, Chandragiri Hills would like to work on some projects to increase its capital before the IPO. Chandragiri Hills has limited resources, it can only finish at most k distinct projects before the IPO. Can you help Chandragiri Hills, by designing the best way to maximize its total capital after finishing at most k distinct projects?
Suppose we have several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. At first, we have W capital. When we finish a project, we will obtain its pure profit and the profit will be added to our total capital.
To sum up, pick a list of at most k distinct projects from given projects list to maximize our final capital, and output the final maximized capital.
So if the input is like − k = 2, W = 0, profit list is like [1,2,4], capital is [0,1,1] ,then the output is 5.
  
 
 
 
 This is because, as we have capital 0 at first, so we can start project at index 0, so we can get profit 1, so capital will be 1. With capital 1, we can start project at index 1 or 2, we will select project at index 2 to get more profit, so the final answer will be 0 + 1 + 4 = 5.

