DSC PC-585 keybus description.

### Summary:

1. [Description](#description)
2. [DSC_585 Series keybus description](#keybus)

------------------------------------------------------------------------------------------------------------------
### Description:

[Back](#summary)

------------------------------------------------------------------------------------------------------------------
### Keybus electrical characteristics:

- Clock period : T = 1ms
- Max voltage : Umax = 12V (Logical 1)
- Min voltage : Umin = 0V (Logical 0)
- Pulses count: 42
- Packet length : ~42 ms
- Delay between packets : ~5ms
- Bit duration : 0.5ms (T/2)

##### Keybus consists of 4 wires:

- Red : +12v
- Yellow: Clock
- Green: Data
- Black : Gnd

##### Keybus oscillogram (click to enlarge):

![Keybus](.docs/dsc585_oscillogram.png) <!-- .element height="50%" width="50%" -->

Description:

| Pulse No | Represents | Description [ logical state ] | Additional info |
|:--------------|:----------------:|:----------------:|:----------------:|
|1.0|TRBL Button|Pushed[0], not pushed[1]| Trouble |
|1.1|TRBL Button|Led is on[1], led is off[0]| |
|2.0|Button 4|Pushed[0], not pushed[1]| |
|2.1|Button 4|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|3.0|Button 5|Pushed[0], not pushed[1]| |
|3.1|Button 5|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|4.0|Button 6|Pushed[0], not pushed[1]|  |
|4.1|Button 6|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|5.0|Button 2nd|Pushed[0], not pushed[1]| |
|5.1|Button 2nd|Led is on[1], led is off[0]| |
|6.0|Button 1|Pushed[0], not pushed[1]|  |
|6.1|Button 1|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|7.0|Button 2|Pushed[0], not pushed[1]|  |
|7.1|Button 2|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|8.0|Button 3|Pushed[0], not pushed[1]| |
|8.1|Button 3|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|9.0|Button BYP|Pushed[0], not pushed[1]| Bypass |
|9.1|Button BYP|Led is on[1], led is off[0]| |
|10.0|Button 0-10|Pushed[0], not pushed[1]| |
|10.1|Button 0-10|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|11.0|Button 11-Stay|Pushed[0], not pushed[1]| |
|11.1|Button 11-Stay|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|12.0|Button 12-Away|Pushed[0], not pushed[1]| |
|12.1|Button 12-Away|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|13.0|Button MEM|Pushed[0], not pushed[1]| Memory |
|13.1|Button MEM|Led is on[1], led is off[0]| |
|14.0|Button 7|Pushed[0], not pushed[1]| |
|14.1|Button 7|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|15.0|Button 8|Pushed[0], not pushed[1]| |
|15.1|Button 8|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|16.0|Button 9|Pushed[0], not pushed[1]|  |
|16.1|Button 9|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|17.0| | | |
|17.1| | | |
|18.0| | | |
|18.1| | | |
|19.0| | | If this impulse drag to gnd (suppress), the 5th zone will be activated |
|19.1| Entering TRBL or MEM menu | [1] - Entered, [0] - Exited | |
|20.0|Reed switch on keyboard | [1] - Opened, [0] - Closed | Keyboard zone, Resistance 1kOhm |
|20.1|Buzzer|[1] - Beeps, [0] - Is silent] | |
|21.0| | | |
|21.1|LED Armed|Led is on[1], led is off[0]| Red led on keyboard |
|22.0|Button CLEAR|Pushed[0], not pushed[1]| |
|22.1| Entering TRBL or MEM menu | [0] - Entered, [1] - Exited | |
|23.0|Button ENTER|Pushed[0], not pushed[1]|  |
|23.1|Button ENTER|Led is on[1], led is off[0]| |
|24.0| | | | 
|24.1|LED Ready|Led is on[1], led is off[0]| Green led on keyboard |


**Unfortunatelly, not all functions of keybus were reversed, but we are working on that :)**


[Back](#summary)

------------------------------------------------------------------------------------------------------------------
