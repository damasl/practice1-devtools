#include "filters.hpp"

Filters* createFiltersOpenCV();
// Declare your implementation here
Filters* createFiltersMaslova();

Filters* createFilters(FILTERS_IMPLEMENTATIONS impl)
{
    switch (impl) {
        case OPENCV:
            return createFiltersOpenCV();
        // Add case for your implementation
        case MASLOVA:
            return createFiltersMaslova();
        default:
            return 0;
    }
}
