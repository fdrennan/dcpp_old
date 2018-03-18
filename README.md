dcpp
================

-   [Introduction](#introduction)
-   [Magellan Algorithm Overviews](#magellan-algorithm-overviews)
    -   [Median-Rank](#median-rank)
    -   [Median-Weighted](#median-weighted)

Introduction
------------

`magellanR` is an R package that houses all the executable R functions for the Adtaxi-Magellan Application. The functions are normally accessed via GET requests to the DeployR API (see section on DeployR). There are 4 high level wrapper functions used by the application, one for each platform:

-   MagellanRTB.R
-   MagellanSOC.R
-   CampaignPacing.R
-   AdvertiserPacing.R

Each wrapper function is controlled by a script that is executed by DeployR when submitting a POST request.

Magellan Algorithm Overviews
----------------------------

For both social and display type advertising campagins, Magellan is used to optimize adset/adgroup budgets. Magellan users have several KPIs (key performance indicator) to choose from to optimize against (cost per action, ROI, ...). Magellan also lets its users select an "aggression level", 0%-100%, to moderate how aggressively budgets are reallocated between adsets/agroups.

When optimizing budgets, Magellan must generally follow a couple of constraints. First, an asdset/adgroup budget cannot be set to below what has already been spent. Second, optimization should not change the campaign's total budget, or in other words, the sum of the incoming adsets/adgroups should equal the sum of the optimized adset/agroups. Currently, magellan uses 2 algorithms to accomplish budget optimization.

### Median-Rank

The median-rank algorithm is used to optimize adset budgets of social campaigns. It works by The steps are as follows:

1.  Compute the user selected KPI. For example, cost per click = cost / clicks.
2.  Rank the adset based on the selected KPI. Ranking can be either ascending or descending, depending on whether a smaller or larger KPI is desirable.
3.  A budget reallocation scheme is computed as a function of
    -   the smallest remaining adset budget
    -   the distances in rank from the median adset
    -   the aggresion level

4.  Apply the reallocation scheme to the budgets of each adset

Notes:

-   Median-Rank will always make adjustments that are symmetric about the median ranking adset/adgroup(s).
-   the maximum change to any adset will be equal to minimum remaining budget % times the selected aggression level.

### Median-Weighted

The Median-Weighted Algorithm is built off of Median-Rank. The difference beyond Median-Rank is that Median-Weighted shapes budget adjustments to reflect the relative differences in the performace. Currently Median-Weighted is used on display campaigns.

Adgroups are split on either side of the median adgroup(s). The adjustment amounts from Median-Rank on lower half (&gt; the median rank), are reweighted base on the the relative performace between them. The same process is then doen on the upper half (&lt; the median rank).
