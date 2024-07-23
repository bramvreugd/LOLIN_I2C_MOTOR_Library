# Arduino library for the new LOLIN I2C MOTOR Shiled
### Installation
- Clone this repository into Arduino/libraries

Bram Vreugdenhil added.
- Error checking. Checking I2c response and motor shield response.
- Speed up code by removing delay and substituting it with buffer checks.
  if you send two motor coands and two dutycycle changes it took >200ms now .724ms both on esp32s3 with 400khz I2C

To do
  - Remove debug serial prints
