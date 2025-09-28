#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp.
//


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if (is_null(p))
        return 0;
    if (is_atom(p))
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}

list append(list p, list q)
{
    if(is_null(p))
    {
        return q;
    }

    return cons(car(p), append(cdr(p), q));
}

bool is_lat(list p)
{
    if(is_null(p))
    {
        return true;
    }

    if(!is_atom(car(p)))
    {
        return false;
    }

    return is_lat(cdr(p));
}

bool member(list p, list q)
{
    if(is_null(q))
    {
        return false;
    }
    if(is_atom(car(q)))
    {
        if(eq(car(q), p))
        {
            return true;
        }

        return member(p, cdr(q));
    }

    if (member(p, car(q)))
    {
        return true;
    }

    return member(p, cdr(q));
}

bool two_the_same(list p, list q)
{
    if(is_null(p))
    {
        return false;
    }


    if(is_atom(car(p)))
    {
        if(member(car(p), q))
        {
            return true;
        }
        return two_the_same(cdr(p), q);
    }

    if (two_the_same(car(p), q))
    {
        return true;
    }


    return two_the_same(cdr(p), q);
}

bool equal(list p, list q) {
    if(is_null(p) && is_null(q))
    {
        return true;
    }
    if(is_null(p) || is_null(q))
    {
        return false;
    }
    if(is_atom(p) && is_atom(q))
    {
        return eq(p, q);
    }
    if(is_atom(p) || is_atom(q))
    {
        return false;
    }


    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}

bool subset(list p, list q)
{
    if(is_null(p))
    {
        return true;
    }

    if(is_atom(car(p)))
    {
        if (!member(car(p), q))
        {
            return false;
        }

        return subset(cdr(p), q);
    }

    if(!subset(car(p), q))
    {
        return false;
    }


    return subset(cdr(p), q);
}


list reverseTopLevel(list p)
{
    if(is_null(p))
    {
        return p;
    }

    return append(reverseTopLevel(cdr(p)), cons(car(p), null()));
}

list last(list p)
{
    if(is_null(cdr(p)))
    {
        return (car(p));
    }

    return last(cdr(p));

}

list list_pair(list p, list q)
{
    if(is_null(p))
    {
        return p;
    }

    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
}

list firsts(list p)
{
    if(is_null(p))
    {
        return p;
    }

    return cons(car(car(p)), firsts(cdr(p)));
}
list flat(list p)
{
    if(is_null(p))
    {
        return p;
    }

    if(is_atom(car(p)))
    {
        return cons(car(p), flat(cdr(p)));
    }

    return append(flat(car(p)), flat(cdr(p)));
}
list total_reverse(list p)
{
    if(is_null(p))
    {
        return p;
    }

    if(is_atom(car(p)))
    {
        return append(total_reverse(cdr(p)), cons(car(p), null()));
    }

    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

list shape(list p)
{
    if (is_null(p))
    {
        return p;
    }

    if (is_atom(car(p)))
    {
        return shape(cdr(p));
    }

    return cons(shape(car(p)), shape(cdr(p)));
}

list intersection(list p, list q)
{
    if(is_null(p))
    {
        return p;
    }

    if(member(car(p), q))
    {
        return cons(car(p), intersection(cdr(p), q));
    }

    return intersection(cdr(p), q);
}

list list_union(list p, list q)
{
    if(is_null(p))
    {
        return q;
    }

    if(member(car(p), q))
    {
        return list_union(cdr(p), q);
    }

    return cons(car(p), list_union(cdr(p), q));
}

list substitute(list old_atom, list new_atom, list p)
{
    if(is_null(p))
    {
        return p;
    }

    if(eq(car(p), old_atom))
    {
        return cons(new_atom, substitute(old_atom, new_atom, cdr(p)));
    }
    
    return cons(car(p), substitute(old_atom, new_atom, cdr(p)));
}

list remove(list p, list a)
{
    if(is_null(p))
    {
        return p;
    }

    if(eq(car(p), a))
    {
        return remove(cdr(p), a);
    }

    return cons(car(p), remove(cdr(p), a));
}


list permute(list p)
{
    if(is_null(p))
    {
        return cons(null(), null());
    }

    return helper(car(p), permute(cdr(p)), null());
}


list helper(list a, list p, list q) 
{
    
    if(is_null(p))
    {
        return null();
    }

    if (is_null(q))
    {
        list r = car(p);      
        list rest = cdr(p);
        if (is_null(r))
        {
            return cons(cons(a, null()), helper(a, rest, null()));
        }
    }

    if(is_null(car(p))) 
    {
        return cons(cons(a, q), helper(a, cdr(p), car(p)));
    }
    else 
    {
        return cons(cons(a, q), cons(cons(car(q), cons(a, cdr(q))), helper(a, p, cdr(q))));
    }
}




