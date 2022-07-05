-- -----------------------------------------------------
-- Schema carRentalDB
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `carRentalDB` DEFAULT CHARACTER SET utf8 ;
USE `carRentalDB` ;

-- -----------------------------------------------------
-- Table `carRentalDB`.`Cars`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `carRentalDB`.`Cars` (
  `carID` INT NOT NULL,
  `regNr` VARCHAR(7) NOT NULL,
  `brand` VARCHAR(45) NOT NULL,
  `color` VARCHAR(45) NOT NULL,
  `transmission` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`carID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `carRentalDB`.`Customers`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `carRentalDB`.`Customers` (
  `customerID` INT NOT NULL,
  `firstName` VARCHAR(45) NOT NULL,
  `lastName` VARCHAR(45) NOT NULL,
  `phone` VARCHAR(8) NOT NULL,
  PRIMARY KEY (`customerID`),
  UNIQUE INDEX `phone_UNIQUE` (`phone` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `carRentalDB`.`Assignment`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `carRentalDB`.`Assignment` (
  `assignmentID` INT NOT NULL,
  `carID` INT NOT NULL,
  `customerID` INT NOT NULL,
  `assignmentDate` DATETIME NOT NULL,
  PRIMARY KEY (`assignmentID`),
  INDEX `carIDFK_idx` (`carID` ASC) VISIBLE,
  INDEX `customerIDFK_idx` (`customerID` ASC) VISIBLE,
  CONSTRAINT `carIDFK`
    FOREIGN KEY (`carID`)
    REFERENCES `carRentalDB`.`Cars` (`carID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `customerIDFK`
    FOREIGN KEY (`customerID`)
    REFERENCES `carRentalDB`.`Customers` (`customerID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;
