# LBYARCH_MCO2
LBYARCH MCO2

Google Drive Folder for Vector Elements:
https://drive.google.com/drive/folders/1ka8_ms5F_SCvAwsTGNa2eAoQQ79deU-4?usp=sharing

Screenshot of the Result After Running the C Reference Program:
![C Program Result](C_Result.png)

Screenshot of the Result After Running the Kernel:
![Kernel Program Result](Kernel_Result.png)

Screenshot of the Results of the C Reference Program and the Kernel Program:
![C Program and Kernel Program Result](C_Kernel_Result.png)

Average Execution Times:<br/>
For 2^20 Double-Precision Floating Point Values - 0.00095 seconds<br/>
For 2^24 Double-Precision Floating Point Values - 0.0138 seconds<br/>
For 2^29 Double-Precision Floating Point Values - 0.4664 seconds<br/>

Analysis: <br/>
After getting the average execution time of each vector, it can be said that the length of the vector and the average execution time are dependent of each other. As the length of each vector increases, the execution time also increases. This is because a vector with a larger length increases the size of the bin file and more memory will be have to be allocated for the read and write operations, resulting to longer execution times.