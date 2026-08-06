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

class Persistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0;
};

class SQLPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to SQL DB" << endl;
    }
};

class MongoPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to Mongo DB" << endl;
    }
};

class FilePersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to File" << endl;
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

    Persistence *sql_db = new SQLPersistence();
    Persistence *mongo_db = new MongoPersistence();
    Persistence *file = new FilePersistence();

    sql_db->save(cart);
    mongo_db->save(cart);
    file->save(cart);

    return 0;
}


/*
Open-Close principle means that the logic should be open for extention but closed for modification.

Without OCP principle above, all the persistence types - sql, mongo and file could have been added to the same class Persistence. But then the same class would have to be modified again and again as new persistence types are supported by the project.

The idea is to use abstraction and then use the interface to extend the functionality using inheritance.
*/