# El Huérfano Orphan List Sorter

El Huérfano is a program primarily designed to be able to sort through the Orphan Well List provided by the Railroad Commission of Texas to provide the user with a list of additions and deletions on the Orphan Well List from one month to the next. **This program only works on Windows.** This guide assumes that you have an understanding of the [RRC Orphan Well List](https://www.rrc.texas.gov/oil-and-gas/research-and-statistics/well-information/orphan-wells-12-months/).

### Disclaimer
This application is still in development and does not yet cover all edge cases. Updates will be made in the future to help accommodate for more varied use cases. For now, I **HIGHLY RECOMMEND** only using this program to sort through the Orphan Lists in their default form, **DIRECTLY DOWNLOADED FROM THE RRC AND UNMODIFIED**.

### Downloading
Navigate to the [releases page](https://github.com/whackfather/el-huerfano/releases) and download the zip file for the latest release of El Huérfano. Unzip the folder, and your download process is complete. I would recommend placing the folder in a safe location and making a desktop shortcut for the application itself.

### Usage
Use the file selectors in the app to choose excel files from your system that you would like to sort through. Make sure to check which column the API numbers are in on each spreadsheet, and also that the spreadsheet has headers. Make sure the listed API column in El Huérfano matches the column the APIs are in. If the spreadsheet does not have headers, or you would not like to use headers, uncheck the "Data has headers" box. I would recommend unchecking the box if your two spreadsheets have different header setups.

You must also select the sorted lists' output locations. You can do this on the right side of the application and place the files anywhere in your file system. If you do not already have a folder you wish to use, I recommend placing them both in Downloads or Documents so they are easy to find.

Once you have filled out all 4 text boxes with file locations, simply press "Output filtered lists", and the sorting process will begin. Once the sorting process is finished, a green message will appear in the bottom left corner of the application letting you know that the process was successful.
