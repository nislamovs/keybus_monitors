#DSC PC-1000 keybus description.

### Summary:

1. [Description](#description)
2. [DSC_PC1000 keybus oscillogram](#oscillogram)
3. [DSC_PC1000 keybus description](#keybus)

------------------------------------------------------------------------------------------------------------------
### Description:

![Panel](.docs/panels_photos/PC1000.png) <!-- .element height="50%" width="50%" -->

[Back](#summary)

------------------------------------------------------------------------------------------------------------------
### Keybus electrical characteristics:

- Clock period : T = 4ms
- Max voltage : Umax = 12V (Logical 1)
- Min voltage : Umin = 0V (Logical 0)
- Pulses count: 8
- Packet length : ~32 ms
- Delay between packets : ~25ms
- Bit duration : 2ms (T/2)

##### Keybus consists of 4 wires:

- Red : +12v
- Yellow: Clock
- Green: Data
- Black : Gnd

##### Keybus oscillogram (click to enlarge):

![Oscillogram](.docs/oscilloscope_photos/PC1000_oscillogram.jpg) <!-- .element height="50%" width="50%" -->

##### Keybus description (click to enlarge):

![Keybus](.docs/pc1000_oscillogram.png) <!-- .element height="50%" width="50%" -->

Description:

| Pulse No | Represents | Description [ logical state ] | Additional info |
|:--------------|:----------------:|:----------------:|:----------------:|
|1.0||||
|1.1|Zone 1 LED|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed  |
|2.0|Button 1,4,7,*|Pushed[0], not pushed[1]| |
|2.1|Zone 2 LED|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|3.0|Button 2,5,8,0|Pushed[0], not pushed[1]| |
|3.1|Zone 3 LED|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|4.0|Button 3,6,9,#|Pushed[0], not pushed[1]|  |
|4.1|Zone 4 LED|Led is on[1], led is off[0]| [1] - zone is opened, [0] - zone is closed |
|5.0|Button *,0,#|Pushed[0], not pushed[1]| |
|5.1|Ready LED|Led is on[1], led is off[0]| Ready led |
|6.0|Button 7,8,9|Pushed[0], not pushed[1]|  |
|6.1|Armed LED|Led is on[1], led is off[0]| Armed led |
|7.0|Button 4,5,6|Pushed[0], not pushed[1]|  |
|7.1|System LED|Led is on[1], led is off[0]| System led |
|8.0|Button 1,2,3|Pushed[0], not pushed[1]| |
|8.1|Buzzer|Buzzer is on[1], Buzzer is off[0]| Buzzer |


**Unfortunatelly, not all functions of keybus were reversed, but we are working on that :)**


[Back](#summary)

------------------------------------------------------------------------------------------------------------------
