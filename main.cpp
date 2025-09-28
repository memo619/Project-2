#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

// Get a list from the user for a specific purpose,
// and output that list
list get_list(std::string purpose) {
    std::cout << "Enter a list for " << purpose << ": ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    return p;
}

void testAllFunctions() {
    auto p = get_list("testing is_lat");
    std::cout << "The list is a list of atoms if 1 is displayed, otherwise 0 will be displayed\n"
        << is_lat(p) << std::endl << std::endl;

    p = get_list("atom to search (member)");
    auto q = get_list("list to search in (member)");
    std::cout << "If atom is found in the list 1 will be displayed, if not 0 will be displayed\n"
        << member(p, q) << std::endl << std::endl;

    p = get_list("testing last");
    std::cout << "The last element of the list is: ";
    write_list(last(p));
    std::cout << std::endl << std::endl;

    p = get_list("first list (list_pair)");
    q = get_list("second list (list_pair)");
    std::cout << "The paired list is: ";
    write_list(list_pair(p, q));
    std::cout << std::endl << std::endl;

    p = get_list("testing firsts");
    std::cout << "The list of first elements is: ";
    write_list(firsts(p));
    std::cout << std::endl << std::endl;

    p = get_list("testing flat");
    std::cout << "The flattened list is: ";
    write_list(flat(p));
    std::cout << std::endl << std::endl;

    p = get_list("first list (two_the_same)");
    q = get_list("second list (two_the_same)");
    std::cout << "If lists share at least one atom 1 will be displayed, if not 0 will be displayed\n"
        << two_the_same(p, q) << std::endl << std::endl;

    p = get_list("first list (equal)");
    q = get_list("second list (equal)");
    std::cout << "If lists are equal 1 will be displayed, if not 0 will be displayed\n"
        << equal(p, q) << std::endl << std::endl;

    p = get_list("testing total_reverse");
    std::cout << "The totally reversed list is: ";
    write_list(total_reverse(p));
    std::cout << std::endl << std::endl;

    p = get_list("testing shape");
    std::cout << "The shape of the list is: ";
    write_list(shape(p));
    std::cout << std::endl << std::endl;

    p = get_list("first set (intersection)");
    q = get_list("second set (intersection)");
    std::cout << "The intersection of the sets is: ";
    write_list(intersection(p, q));
    std::cout << std::endl << std::endl;

    p = get_list("first set (list_union)");
    q = get_list("second set (list_union)");
    std::cout << "The union of the sets is: ";
    write_list(list_union(p, q));
    std::cout << std::endl << std::endl;

    p = get_list("old atom (substitute)");
    q = get_list("new atom (substitute)");
    auto r = get_list("list of atoms (substitute)");
    std::cout << "The list with substitutions is: ";
    write_list(substitute(p, q, r));
    std::cout << std::endl << std::endl;

    p = get_list("list of atoms (remove)");
    q = get_list("atom to remove");
    std::cout << "The list with atom removed is: ";
    write_list(remove(p, q));
    std::cout << std::endl << std::endl;

    p = get_list("first list (subset)");
    q = get_list("second list (subset)");
    std::cout << "If first is subset of second 1 will be displayed, if not 0 will be displayed\n"
        << subset(p, q) << std::endl << std::endl;

    p = get_list("testing permute");
    std::cout << "All permutations of the list are: ";
    write_list(permute(p));
    std::cout << std::endl;
}

int main() {

    testAllFunctions();

    return 0;
}