import time
import json
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


def Login(username, password):
    #Connects to website
    title = driver.title
    driver.implicitly_wait(50)
    emailLogin = driver.find_element(By.XPATH,"/html/body/div[2]/div/div[2]/div[2]/div[1]/div[3]/form/div[1]/div[1]/input")
    passLogin = driver.find_element(By.XPATH,"/html/body/div[2]/div/div[2]/div[2]/div[1]/div[3]/form/div[1]/div[2]/input")

    #Inputs username and password
    emailLogin.send_keys(username)
    passLogin.send_keys(password)

    #Attempt login
    driver.find_element(By.XPATH, "//*[@id='game-frame']/div/div[2]/div[2]/div[1]/div[3]/form/div[3]/button").click()

    #Confirm login
    try:
        driver.implicitly_wait(30)
        myworldsVisible = driver.find_element(By.XPATH, "//*[@id='choose-world-scene']/div[1]")

        if myworldsVisible.is_displayed():
            print("Login Successful")
        else:
            print("Login Failed")
            exit()
    except:
        print("Login Failed")
        exit()
def checkWorlds():
    driver.implicitly_wait(50)
    i = 1
    worldSelection = {}
    while True:
        driver.implicitly_wait(50)
        try:
            #Attempts to print world names and load them into dictionary
            worldName = driver.find_element(By.XPATH, f"//*[@id='choose-world-scene']/div[2]/div[2]/div[{i}]/div[2]/div[1]").text
            driver.implicitly_wait(50)
            print(worldName)
            worldSelection[worldName] = (f"//*[@id='choose-world-scene']/div[2]/div[2]/div[{i}]")
            i += 1
        except:
            print("No more worlds")
            break

            #Select World - Will change in future
    worldChoice = input("Enter world to login to: ")
    try:
        #Takes XPATH from the worldSelection dict and attempts to login to world
        driver.find_element(By.XPATH, worldSelection[worldChoice]).click()
        print("Successfully Logged In")
    except:
        print("Failed, incorrect world name")

    print("Exiting")
def updateNameandResources():
    driver.implicitly_wait(10)
    i = 1
    for castle in castle_data["castle"]:
        for resources in castle["resources"]:
            try:
                resource = driver.find_element(By.XPATH, f"//*[@id='game-bar-top']/div/div[2]/div/div[2]/div[{i}]/div[2]/div[1]").text
                castle["resources"][resources] = int(resource)
                i+=1
            except:
                print("Updated")

    for castle in castle_data["castle"]:
        print(castle["resources"])

def updateMainBuildings():
    i = 2
    #Opens Building List
    try:
        buildingListButton = driver.find_element(By.XPATH, '//*[@id="game-bar-top"]/div/div[1]/div[1]/div[2]')
    except:
        print("Unable to show buildings ")

    #Update Building Levels
    for castle in castle_data["castle"]:
        for level in castle["buildings"]:
            while i <= 7:
                buildingLevel = driver.find_element(By.XPATH, f'//*[@id="menu-section-general-container"]/div/div[2]/div[{i}]/div[2]/div/div[2]')
                castle["buildings"][level] = buildingLevel
                i+=1

def cycleThroughCastles():
    wait = WebDriverWait(driver, timeout=30)

    # Ensure loading overlay is invisible before clicking the first time
    wait.until(EC.invisibility_of_element((By.ID, "over-layer--game-loading")))

    selectNextCastle = driver.find_element(By.XPATH, '//*[@id="game-bar-top"]/div/div[2]/div/div[1]/div[3]')
    listOfCastles = []

    while True:
        wait.until(EC.invisibility_of_element((By.ID, "over-layer--game-loading")))
        selectNextCastle.click()
        castleName = driver.find_element(By.XPATH, f'//*[@id="game-bar-top"]/div/div[2]/div/div[1]/div[2]/span[1]').text
        if castleName in listOfCastles:
            break
        else:
            listOfCastles.append(castleName)
    print("Finished with castle names")
    return listOfCastles


def addCastlesToJson(nameofCastles):
    if not all(isinstance(name, str) for name in nameofCastles):
        raise ValueError("All elements in nameofCastles must be strings.")
    for i in range(len(nameofCastles)):
        castle_data["castle"].append({
            "id": len(castle_data["castle"]) + 1,
            "castle_name": nameofCastles[i],  # Ensure this is a single string
            "resources": {
                "wood": 0,
                "stone": 0,
                "ore": 0,
                "Population": 0,
                "copper": 0,
                "silver": 0
            },
            "core buildings": [
                {"type": "Keep", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Arsenal", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Tavern", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Library", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Fortifications", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Market", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Farm", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Lumberjack", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Wood Store", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Quarry", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Stone Store", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Ore Mine", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True},
                {"type": "Ore Store", "level": 1, "next_upgrade_time": 0, "upgrade_possible": True}
            ],
            "resource buildings": [
                {"type": "Farm", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Lumberjack", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Wood Store", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Quarry", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Stone Store", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Ore Mine", "level": 1, "upgrade_time": 0, "upgrade_possible": True},
                {"type": "Ore Store", "level": 1, "upgrade_time": 0, "upgrade_possible": True}
            ]
        })


    # Save to JSON
    import json
    with open('castles.json', 'w') as json_file:
        json.dump(castle_data, json_file, indent=4)

def convertToString(input_list):
    flat_list = []
    for item in input_list:
        if isinstance(item, list):
            flat_list.extend(convertToString(item))  # Recursively flatten
        else:
            flat_list.append(str(item))  # Convert to string if not already
    return flat_list

if __name__ == "__main__":
    # Load castle data from the JSON file
    with open('castles.json', 'r') as json_file:
        castle_data = json.load(json_file)

    # Open Chrome browser w/ Selenium
    driver = webdriver.Chrome()
    driver.implicitly_wait(30)
    driver.get("https://lordsandknights.com")
    Login("removed for privacy","removed for privacy")
    checkWorlds()
    castleNames = [cycleThroughCastles()]
    castleNames = convertToString(castleNames)
    addCastlesToJson(castleNames)
    #updateNameandResources()
 with open('castles.json', 'w') as json_file:
        json.dump(castle_data, json_file, indent=4)