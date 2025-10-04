# SoRea
*Created by [Rea Sklika](https://github.com/reasklika) and [Sofia Sotiriou](https://github.com/sofiasotiriou)*

An interface for displaying movies and descriptions using C++ and the SGG library provided by AUEB.

## Description and Walkthrough
 - The "SoRea" interface contains a home screen, a description screen, a genre-based screen and a year-based screen.

- The home screen contains six movies at a time, with a total of 18 movies that can be seen through the navigation arrows on each side of the presented movies. 


<img src="https://github.com/user-attachments/assets/05c46da7-ede2-4bcb-a98f-0b895adf4753" width="45%" />
<img src="https://github.com/user-attachments/assets/1869d11e-b208-4360-8842-02de3d4c4bc6" width="45%">

<br>

- The description screen adds a description box for the chosen movie and highlights the described movie.

<img src="https://github.com/user-attachments/assets/a5b2806a-8126-4132-98bb-105f0431db53" width="60%"> 

<br>

- The genre-based screen appears when one taps one one of the six genre buttons on the top-right corner. It shows the movies that correspond to the chosen genre and a return button that redirects to the home screen. In the genre-based screen the user can once again choose to see the description of one of the displayed movies. 


<img src="https://github.com/user-attachments/assets/7f876189-3b90-4c10-ab29-1a55b1b9841b" width="45%"> 
<img src="https://github.com/user-attachments/assets/dd64e55e-90f3-41a0-9f25-c592cce65732" width="45%">

<br>

- Similarly, the year-based screen appears when the used glides the slider to their desired year. The movies produced in that year appear along with the return button. and again, the description appears when a movie is selected. 


<img src="https://github.com/user-attachments/assets/fcfc4b6e-33cb-4985-99ae-2bf35db679f2" width="45%">
<img src="https://github.com/user-attachments/assets/02e1990b-1b3a-4c31-99e8-d880f4d95cc2" width="45%">

<br>

- The movies where chosen at random (along the obvious theme), so there can be multiple movies in a year, or even none.  

<img src="https://github.com/user-attachments/assets/fb05b24e-161a-4df9-943e-96a3a71d0c04" width="50%">


## Code structure 

The UI is managed in 'interface.cpp'. 

The widget class ('widget.h') is inherited by all the widgets (slider- 'slider.cpp' and button- 'button.h'). 

The buttons are further divided to: 
- Genre button ('genrebutton.cpp'): The six buttons representing the different genres. 
- Arrow button ('arrowbutton.cpp'): The two arrow buttons that lead to more movies in the home screen. 
- Return button ('returnbutton.cpp'): The button in the genre-based and year-based screens that leads back to the home screen. 
- Movie button ('moviebutton.cpp'): Manages the creation of the description box when a movie is selected. 

More information on building the SGG library in order to run this project can be found [here](https://cgaueb.github.io/sgg/index.html).

