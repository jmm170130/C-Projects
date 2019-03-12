//specification file for the rectangle class. Declaration of the Rectangle class

#ifndef RECTANGLE_H //if class has not been defined continue. include guard

#define RECTANGLE_H

class Rectangle
{

	private: //private member variables
		double height;
		double length;
	public: //public member functions
		void setHeight(double); //set the height of the rectangle
		void setLength(double);//set the length of the rectangle

		double getHeight() const //display height of rectangle
		{ return height; }

		double getLength() const //display length of rectangle
		{ return length; }

		double getArea() const		//calculate and display area of the rectangle
		{ return height * length; }

		double getPerimeter() const //calculate and display perimeter of rectangle
		{ return (height * 2) + (length * 2); }


};
#endif



