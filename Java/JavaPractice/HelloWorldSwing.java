// Create a window that says hi to the user
// This is dumb, but I've never made a window
// that's interactable before

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HelloWorldSwing extends JFrame implements ActionListener
{
    // Initialize variables
    private static final long serialVersionUID = 1L;    // Don't know why this is needed, but it fixes an error

    private JLabel      labelQuestion;                  // Outputs "Who are you?"
    private JLabel      labelName;                      // Asks user's name
    private JTextField  fieldName;                      // Name field
    private JButton     buttonSayHi;                    // Submit name button

    public HelloWorldSwing()
    {
        // Names window
        super("Hello!");

        // Initialize all variables
        initComponents();

        // Set window size
        setSize(300, 200);
        // Give an exit
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void initComponents()
    {
        // Naming things
        labelQuestion   =   new JLabel("Who are you?");
        labelName       =   new JLabel("My name is...");
        fieldName       =   new JTextField(10); // Give some space for names
        buttonSayHi     =   new JButton("Say hello!");

        // Lays out the window one by one
        // Need more practice with it, but seems
        // to be pretty simple. Put something in 
        // & it gets automatically organized
        setLayout(new FlowLayout());

        // Add everything needed
        add(labelQuestion);
        add(labelName);
        add(fieldName);
        add(buttonSayHi);

        // Say hi button
        buttonSayHi.addActionListener(this);
    }

    public void actionPerformed(ActionEvent event)
    {
        // Initialize message string
        String message = "Greetings, %s!";

        // Get some info from user
        String name = fieldName.getText();
        String designation = sayHello(name);

        // Format string and message
        message = String.format(message, designation);

        // Show the actual message
        JOptionPane.showMessageDialog(this, message);
    }

    private String sayHello(String name)
    {
        // Just returns the name
        return name;
    }

    public static void main(String[] args)
    {
        // Creates instance of "Hello!" App
        new HelloWorldSwing().setVisible(true);
    }

}