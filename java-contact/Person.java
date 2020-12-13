
class Person {
    private String phoneNumber = null;
    private String name = null;
    private String email = null;
    
    public Person (String name, String phoneNumber, String email) {
        this.phoneNumber = phoneNumber;
        this.name = name;
        this.email = email;
    }

    public void setPhoneNumber (String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public void setName (String name) {
        this.name = name;
    }
    public void setEmail (String email) {
        this.email = email;
    }
    public String getName () {
        return name;
    }

    public void printContact() {
        System.out.println("Name: " + this.name);
        System.out.println("Phone number: " + this.phoneNumber);
        System.out.println("Email: " + this.email);
        System.out.println();
    }


}