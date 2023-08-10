#include "Vector.h" // Assuming the above file is saved as Vector.h

int main() {
    // Create two 3D vectors of type int
    scaleGeom::Vector<float> vec1(5.1, 6.2, 8.3);
    scaleGeom::Vector<float> vec2(4.2, 5.1, 6.5);
/*
    // Test addition
    auto vec3 = vec1 + vec2;
    // Here, you can print the resulting vector if you have implemented a print function or an overloaded stream operator for the Vector class

    // Test subtraction
    auto vec4 = vec1 - vec2;
    // Again, you can print the resulting vector

    // Test equality
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal" << std::endl;
    }
    else {
        std::cout << "vec1 and vec2 are not equal" << std::endl;
    }

    // Test inequality
    if (vec1 != vec2) {
        std::cout << "vec1 and vec2 are different" << std::endl;
    }
    else {
        std::cout << "vec1 and vec2 are the same" << std::endl;
    }

    // print results of addition and subtraction
    std::cout << "vec1 + vec2 = " << vec3 << std::endl;
    std::cout << "vec1 - vec2 = " << vec4 << std::endl;

    if (vec1 < vec2) {
		std::cout << "vec1 is less than vec2" << std::endl;
	}
    else {
		std::cout << "vec1 is not less than vec2" << std::endl;
	}

    //print vec1 > vec2
    if (vec1 > vec2) {
        std::cout<<"vec1 is greater than vec2"<<std::endl;
    }
    else {
		std::cout<<"vec1 is not greater than vec2"<<std::endl;
	}

    //print dot product of vec1 and vec2
    auto result = scaleGeom::dotProduct(vec1, vec2);
    std::cout<<"dot product of vec1 and vec2 is "<<result<<std::endl;

    //print cross product of vec1 and vec2
    auto result2 = scaleGeom::crossProduct3D(vec1, vec2);
    std::cout<<"cross product of vec1 and vec2 is "<<result2<<std::endl;

    //print magnitude of vec1
    auto result3 = vec1.magnitude();
    vec1.normalize();
    std::cout<<"magnitude of vec1 is "<<result3<<std::endl;
    std::cout<<"Normalized vec1 is "<<vec1<<std::endl;

*/

    return 0;
}
