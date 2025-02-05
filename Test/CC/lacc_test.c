//------------------------------------------------------------------------------
// lacc_test: test LAGraph_lacc
//------------------------------------------------------------------------------

/*
    LAGraph:  graph algorithms based on GraphBLAS

    Copyright 2019 LAGraph Contributors.

    (see Contributors.txt for a full list of Contributors; see
    ContributionInstructions.txt for information on how you can Contribute to
    this project).

    All Rights Reserved.

    NO WARRANTY. THIS MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. THE LAGRAPH
    CONTRIBUTORS MAKE NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR IMPLIED,
    AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF FITNESS FOR
    PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS OBTAINED FROM USE OF
    THE MATERIAL. THE CONTRIBUTORS DO NOT MAKE ANY WARRANTY OF ANY KIND WITH
    RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.

    Released under a BSD license, please see the LICENSE file distributed with
    this Software or contact permission@sei.cmu.edu for full terms.

    Created, in part, with funding and support from the United States
    Government.  (see Acknowledgments.txt file).

    This program includes and/or can make use of certain third party source
    code, object code, documentation and other files ("Third Party Software").
    See LICENSE file for more details.

*/

// Contributed by Tim Davis, Texas A&M

#include "LAGraph.h"

#define LAGRAPH_FREE_ALL    \
{                           \
    GrB_free (&A) ;         \
}


int main (int argc, char **argv)
{
    GrB_Info info ;
    GrB_Matrix A = NULL ;
    GrB_init (GrB_NONBLOCKING) ;
    // self edges are OK

    FILE *f ;
    if (argc == 1)
    {
        f = stdin ;
    }
    else
    {
        f = fopen (argv[0], "r") ;
        if (f == NULL)
        {
            printf ("unable to open file [%s]\n", argv[0]) ;
            return (GrB_INVALID_VALUE) ;
        }
    }

    LAGRAPH_OK (LAGraph_mmread (&A, f)) ;

    LAGRAPH_OK (LAGraph_lacc (A)) ;

    LAGRAPH_FREE_ALL ;
    LAGRAPH_OK (GrB_finalize ( )) ;
}

