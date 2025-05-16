#include <memory>
#include <iostream>

struct Point {
    double X{0.0};
    double Y{0.0};
    Point(double _x, double _y): X(_x), Y(_y) {};
};


int main(int argc, char *argv[])
{
    {
        // Block with raw pointer lifecycle
        double* d = new double (1.0);
        Point* pt = new Point(1.0, 2.0); // Two-d Point class
        // Dereference and call member functions
        *d = 2.0;
        (*pt).X = 3.0; // Modify x coordinate
        (*pt).Y = 3.0; // Modify y coordinate
        std::cout << *d << std::endl;
        std::cout<<pt->X<<" "<<pt->Y<<std::endl;
        // Can use operators for pointer operations
        pt->X = 5.0; // Modify x coordinate
        pt->Y = 6.0; // Modify y coordinate
        std::cout<<pt->X<<" "<<pt->Y<<std::endl;
        // Explicitly clean up memory (if you have not forgotten)
        delete d;
        delete pt;
    }

    {
        // TODO: Rewrite the above code using smart pointers
        auto d = std::make_unique<double>(1.0);
        auto pt = std::make_unique<Point>(1.0, 2.0);
        auto p {std::make_unique<Point>(10.0, 13.0)};
        std::cout<<p->X<<" "<<p->Y<<std::endl;
        *d = 2.0;
        pt->X = 3.0;
        pt->Y = 3.0;
        std::cout << *d << std::endl;
        std::cout<<pt->X<<" "<<pt->Y<<std::endl;
        pt->X = 5.0;
        pt->Y = 6.0;
        std::cout<<pt->X<<" "<<pt->Y<<std::endl;
    }

    {
        // Block with raw pointer lifecycle
        double* d = new double (1.0);
        Point* pt1 = new Point(1.0, 2.0); // Two-d Point class
        Point* pt2 = pt1;
        // Dereference and call member functions
        *d = 2.0;
        (*pt1).X = 3.0; // Modify x coordinate
        (*pt1).Y = 3.0; // Modify y coordinate
        std::cout<<pt2->X<<" "<<pt2->Y<<std::endl;
        // dereference pt1
        pt1 = nullptr;
        pt2->X = 5.0; // Modify x coordinate
        pt2->Y = 6.0; // Modify y coordinate
        std::cout<<pt2->X<<" "<<pt2->Y<<std::endl;
        // Explicitly clean up memory (if you have not forgotten)
        delete d;
        delete pt2;

    }

    {
        // TODO: Rewrite the above code using smart pointers
        // Bonus: inspect the p.use_count() of the shared_ptr
        auto d = std::make_unique<double>(1.0);
        auto pt1 = std::make_shared<Point>(1.0, 2.0); // Two-d Point class
        std::cout<<pt1.use_count()<<" "<<std::endl;
        auto pt2 = pt1;
        std::cout<<pt1.use_count()<<" "<<pt2.use_count()<<std::endl;
        // Dereference and call member functions
        *d = 2.0;
        (*pt1).X = 3.0; // Modify x coordinate
        (*pt1).Y = 3.0; // Modify y coordinate
        std::cout<<pt2->X<<" "<<pt2->Y<<std::endl;
        // dereference pt1
        std::cout<<pt1.use_count()<<" "<<pt2.use_count()<<std::endl;
        pt1 = nullptr;
        std::cout<<pt1.use_count()<<" "<<pt2.use_count()<<std::endl;
        pt2->X = 5.0; // Modify x coordinate
        pt2->Y = 6.0; // Modify y coordinate
        std::cout<<pt2->X<<" "<<pt2->Y<<std::endl;

    }

}
