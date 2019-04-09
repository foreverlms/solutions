import com.bob.Solution;

import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
//        Scanner in = new Scanner(System.in);
//
//        System.out.println(in.hasNext());
//        int a = in.nextInt();
//        System.out.println("here");
//        int b = in.nextInt();
//        System.out.println(a);
//        System.out.println(b);
//        while (in.hasNext()){
//            int a = in.nextInt();
//            int b = in.nextInt();
//            System.out.println(a);
//            System.out.println(b);
//        }

        A a = B.test();
        B foo = new B();

        System.out.println(a.b);
        System.out.println(foo.b);

//        A bar = a.test();
    }
}

class A {
    static int b = 5;
    public static A test(){
        return new A();
    }

    public int a = 10;

}

class B extends A{
    static int b = 100;
    public static B test(){
        System.out.println("B");
        return new B();
    }
}