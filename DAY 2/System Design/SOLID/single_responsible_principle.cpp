#include <iostream>
#include <vector>
using namespace std;

// the product class provides the product details
class Product
{
private:
    string name;
    double price;

public:
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }

    string get_name()
    {
        return this->name;
    }

    double get_price()
    {
        return this->price;
    }
};

// The ShoppingCart class add the product to the shopping cart and then calculates the total price of the products in the cart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    const vector<Product *> get_products()
    {
        return products;
    }

    double calculateTotal()
    {
        double totalPrice = 0;
        for (auto product : products)
        {
            totalPrice += product->get_price();
        }

        return totalPrice;
    }
};

// The ShoppingCartPrinter class prints the invoice of the products in the shopping cart
class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        cout << "Shopping Cart Invoice" << endl;
        for (auto product : this->cart->get_products())
        {
            cout << product->get_name() << " " << product->get_price() << endl;
        }

        cout << "Total Price: " << this->cart->calculateTotal() << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000.00));
    cart->addProduct(new Product("Keyboard", 5000.00));
    cart->addProduct(new Product("Mouse", 500.00));

    ShoppingCartPrinter *invoice = new ShoppingCartPrinter(cart);
    invoice->printInvoice();

    return 0;
}

/*
Notice how the ShoppingCart class just calculates the total price and add the products into the cart.

the reponsibility of the ShoppingCart class just does that.

While the ShoppingClassPrinter class uses the ShoppingCart class to print the invoice of the products.

This is an example of how the S from SOLID, i.e., single reponsibility priciple can be used.
*/