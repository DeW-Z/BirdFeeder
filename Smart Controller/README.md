<h1>BirdFeeder Controller PCB</h1>

<hr>

<blockquote>

<h2 id="development-disclaimer">Development Status & Disclaimer</h2>

<p>
  This controller is currently considered a development and evaluation board. While it includes multiple safety and fault-detection features such as break-beam stopping, jam detection, motor disable logic, and status monitoring, it has not been certified or evaluated as a commercial safety-rated control system.
</p>

<p>
  The board should be treated as experimental hardware and should only be used by individuals familiar with electronics, motors, and embedded systems. The controller should not be relied upon for life safety, fire prevention, equipment protection, or unattended long-term operation.
</p>

<p>
  Do not leave the system operating unattended. Always supervise operation during testing, tuning, calibration, firmware updates, and normal feeder use.
</p>

<p>
  Users are responsible for:
</p>

<ul>
  <li>Providing appropriate power protection and wiring.</li>
  <li>Ensuring the feeder mechanism is mechanically safe.</li>
  <li>Verifying sensor operation before use.</li>
  <li>Inspecting the system regularly for jams, overheating, wear, or unexpected behavior.</li>
  <li>Disconnecting power before servicing or modifying the system.</li>
</ul>

<p>
  By using this hardware and firmware, the user accepts all responsibility and risk associated with installation and operation.
</p>

</blockquote>

<hr>

<p>
  The BirdFeeder Smart Controller is the next generation of stepper motor controller for the BirdFeeder Bullet Feeder. It works with standard USB Type-C power supplies and can utilize up to 20 volts with compatible PD power supplies. The standard BreakBeam sensor, Speed Adjuster and Stepper Motor connectors are still here, but this version also adds additional inputs and outputs for future development and add-ons.
</p>

<p>
  The biggest change, though, is Wi-Fi support.
</p>

<p>
  Now, I get it. Great, another Wi-Fi device. Honestly, I had the same hesitation when I started working on this version. Over the last couple years, I’ve spent a pretty good amount of time helping people get the original PCB up and running, and the biggest hurdle was almost always setting up Arduino IDE, drivers, libraries and firmware updates.
</p>

<p>
  The goal with the Smart Controller wasn’t to overcomplicate the feeder, it was actually the opposite. I wanted to make setup, troubleshooting and updates easier for people who just want to get the feeder running without needing development tools.
</p>

<p>
  This version can be configured, controlled, updated and diagnosed completely through the built-in web portal. It also adds features that were difficult or impossible on the original board, including:
</p>

<ul>
  <li>Built-in WiFi setup and browser-based controls.</li>
  <li>OTA firmware updates through the web page.</li>
  <li>Integrated diagnostics and logging.</li>
  <li>Built-in StallGuard jam detection.</li>
  <li>Additional inputs and outputs for future accessories and add-ons.</li>
  <li>Cleaner installation and easier troubleshooting.</li>
</ul>

<p>
  Can I make it myself? It isn’t open-source <em>yet</em>, but it will be in the future. That being said, this design uses mostly 0402 SMD components and other very small parts. Trying to hand solder these reliably is probably going to be rough unless you already have experience with small SMD work and proper equipment.
</p>

<p>
  Once available, you’ll be able to order these through a service like JLCPCB’s PCBA service, although the minimum order quantity is typically 5 assembled boards.
</p>

<p>
  Ultimately, switching to this design allows me to reduce cost, keep stock on hand more reliably and get people up and running much easier, for roughly the same price, or even slightly less than the original board.
</p>

<p>
  That said, the original design is still great and will continue to be available for people who enjoy building and experimenting with electronics themselves. I’ll continue ordering the original PCBs, but I will no longer be building complete assembled versions of that design.
</p>

<p>
  Normal operation does not require internet access, a mobile app, an account, or anything of the sort. This will function 100% offline.
</p>

<hr>

<h2 id="table-of-contents">Table of Contents</h2>

<ol>
  <li><a href="#what-this-controller-does">What This Controller Does</a></li>
  <li><a href="#main-features">Main Features</a></li>
  <li><a href="#important-safety-notes">Important Safety Notes</a></li>
  <li><a href="#quick-start">Quick Start Guide</a></li>
  <li><a href="#hardware-overview">Hardware Overview</a></li>
  <li><a href="#stepper-motor-phase-swap-header">Stepper Motor Phase Swap Header</a></li>
  <li><a href="#status-leds-and-indicators">Status LEDs and Indicators</a></li>
  <li><a href="#first-time-setup">First-Time Setup</a></li>
  <li><a href="#connecting-to-wifi">Connecting to WiFi</a></li>
  <li><a href="#using-standalone-mode">Using Standalone Mode</a></li>
  <li><a href="#opening-the-control-page">Opening the Control Page</a></li>
  <li><a href="#main-control-page">Main Control Page</a></li>
  <li><a href="#mode-button-operation">Mode Button Operation</a></li>
  <li><a href="#break-beam-sensor">Break-Beam Sensor</a></li>
  <li><a href="#jam-detection-stallguard">Jam Detection / StallGuard</a></li>
  <li><a href="#motor-tuning-settings">Motor Tuning Settings</a></li>
  <li><a href="#stallguard-calibration">StallGuard Calibration</a></li>
  <li><a href="#settings-and-diagnostics-page">Settings and Diagnostics Page</a></li>
  <li><a href="#firmware-updates">Firmware Updates</a></li>
  <li><a href="#resetting-onboarding">Resetting Onboarding</a></li>
  <li><a href="#troubleshooting">Troubleshooting</a></li>
  <li><a href="#technical-reference">Technical Reference</a></li>
  <li><a href="#support-information-to-provide">Support Information to Provide</a></li>
</ol>

<hr>

<h2 id="what-this-controller-does">What This Controller Does</h2>

<p>
  The controller runs a stepper motor that drives the feeder mechanism. It can be operated from a browser-based control page, a physical mode button, and a physical speed knob. The board creates its own setup WiFi network, can connect to a home WiFi network, and serves its control page directly from the device.
</p>

<p>
  The controller is intended to be simple for normal use, but still provides advanced diagnostics and tuning options for setup, testing, and support.
</p>

<hr>

<h2 id="main-features">Main Features</h2>

<ul>
  <li>Local browser-based control page served directly from the controller.</li>
  <li>First-time WiFi setup using the built-in <strong>BirdFeeder Setup</strong> access point.</li>
  <li>Optional standalone mode for use without a home WiFi network.</li>
  <li>mDNS local address support using <strong>birdfeeder.local</strong> by default.</li>
  <li>Physical speed knob or app-based speed slider.</li>
  <li>Forward and reverse motor direction control.</li>
  <li>Single-button local start/stop control.</li>
  <li>Double-press local direction reversal.</li>
  <li>Break-beam sensor stopping.</li>
  <li>Automatic motor resume after the break beam clears, when the motor was stopped by the break beam.</li>
  <li>TMC2209 StallGuard-based jam detection.</li>
  <li>On-device diagnostic log.</li>
  <li>OTA firmware update page.</li>
  <li>Light and dark UI theme support.</li>
</ul>

<hr>

<h2 id="important-safety-notes">Important Safety Notes</h2>

<ul>
  <li>Do not place fingers, tools, or loose objects into the feeder mechanism while the motor is enabled.</li>
  <li>The break-beam and jam-detection features are protective controls, but they should not be treated as a substitute for safe mechanical design.</li>
  <li>Always disconnect power before wiring sensors, changing motor wiring, or working near exposed electronics.</li>
  <li>Use a properly rated power supply for the motor and controller.</li>
  <li>If the motor moves unexpectedly, stop the motor from the web interface or remove power.</li>
  <li>If a jam repeatedly occurs, inspect the feeder mechanism before increasing trip thresholds.</li>
</ul>

<hr>

<hr>

<h2 id="quick-start">Quick Start</h2>

<p>
  Just want to get the feeder running? Start here.
</p>

<ol>
  <li>Connect the stepper motor, BreakBeam sensor and speed adjuster.</li>
  <li>Connect a USB Type-C power supply.</li>
  <li>Wait a few seconds for the controller to boot.</li>
  <li>On your phone or computer, connect to the WiFi network:<br>
    <strong>BirdFeeder Setup</strong>
  </li>
  <li>Password:<br>
    <strong>12345678</strong>
  </li>
  <li>Open a browser and go to:<br>
    <strong>http://192.168.4.1</strong>
  </li>
  <li>Use the setup page to:
    <ul>
      <li>Connect the controller to your home WiFi, or</li>
      <li>Continue using standalone mode</li>
    </ul>
  </li>
  <li>Once connected to WiFi, open:<br>
    <strong>http://birdfeeder.local</strong>
  </li>
</ol>

<p>
  If the motor vibrates or buzzes instead of spinning normally, see the
  <a href="#stepper-motor-phase-swap-header">Stepper Motor Phase Swap Header</a>
  section below.
</p>

<hr>

<h2 id="hardware-overview">Hardware Overview</h2>

<p>
  The PCB is built around an ESP32-S3 microcontroller and a TMC2209 stepper driver. The ESP32-S3 handles WiFi, the web interface, sensor monitoring, button input, LED status output, and motor step generation. The TMC2209 drives the stepper motor and provides StallGuard feedback for jam detection.
</p>

<h3>Major Functional Blocks</h3>

<table>
  <thead>
    <tr>
      <th align="left">Block</th>
      <th align="left">Purpose</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>ESP32-S3</td>
      <td>Main processor, WiFi, local web server, sensor logic, and motor control.</td>
    </tr>
    <tr>
      <td>TMC2209 Stepper Driver</td>
      <td>Drives the stepper motor using STEP/DIR control and provides StallGuard readings.</td>
    </tr>
    <tr>
      <td>Speed Potentiometer</td>
      <td>Physical speed control knob.</td>
    </tr>
    <tr>
      <td>Break-Beam Sensor Input</td>
      <td>Stops the feeder when the beam is blocked.</td>
    </tr>
    <tr>
      <td>Status LEDs</td>
      <td>Show motor, break-beam, and jam status.</td>
    </tr>
    <tr>
      <td>Mode Button</td>
      <td>Local start/stop and direction control.</td>
    </tr>
    <tr>
      <td>USB-C PD / Power Good Monitoring</td>
      <td>Monitors whether the power system reports ready power.</td>
    </tr>
  </tbody>
</table>

<hr>

<h2 id="stepper-motor-phase-swap-header">Stepper Motor Phase Swap Header (3x2 Header)</h2>

<p>
  One issue that occasionally comes up with stepper motors is that the motor may vibrate, buzz or twitch instead of spinning normally. This is almost always caused by the inner pair of stepper motor wires being reversed.
</p>

<p>
  To make this easier to troubleshoot, the Smart Controller includes a dedicated 3x2 phase-swap header between the stepper motor and the driver. Instead of cutting and re-pinning wires, you can simply move the jumper to swap the inner motor pair.
</p>

<p>
  If your motor:
</p>

<ul>
  <li>Vibrates but does not rotate</li>
  <li>Feels rough or inconsistent</li>
  <li>Locks up and buzzes loudly</li>
  <li>Moves only slightly back and forth</li>
</ul>

<p>
  Power the controller off and move the phase-swap jumper to the opposite position, then test the motor again.
</p>

<p>
  This header only swaps the inner coil pair. It does not change motor direction. Normal direction changes should still be done through the web interface or mode button.
</p>

<p>
  In most cases, once the correct phase orientation is found, the jumper should not need to be changed again unless a different motor is installed.
</p>

<hr>

<h2 id="status-leds-and-indicators">Status LEDs and Indicators</h2>

<p>
  The board has three main status LED outputs. The web interface also shows matching status cards on the control page.
</p>

<table>
  <thead>
    <tr>
      <th align="left">Indicator</th>
      <th align="left">Meaning</th>
      <th align="left">Normal State</th>
      <th align="left">Fault / Alert State</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Motor / Running LED</td>
      <td>Shows whether the motor is currently enabled.</td>
      <td>On when running.</td>
      <td>Off when stopped.</td>
    </tr>
    <tr>
      <td>Break-Beam LED</td>
      <td>Shows whether the break-beam sensor is blocked.</td>
      <td>Clear / normal.</td>
      <td>Turns on when the beam is blocked.</td>
    </tr>
    <tr>
      <td>Jam / StallGuard LED</td>
      <td>Shows whether a jam or StallGuard stop has occurred.</td>
      <td>Off / OK.</td>
      <td>Turns on when a jam fault is active or latched.</td>
    </tr>
  </tbody>
</table>

<hr>

<h2 id="first-time-setup">First-Time Setup</h2>

<ol>
  <li>Power the controller using the correct power supply.</li>
  <li>Wait a few seconds for the controller to boot.</li>
  <li>On a phone, tablet, or computer, open the WiFi network list.</li>
  <li>Connect to the setup network named <strong>BirdFeeder Setup</strong>.</li>
  <li>Use the setup password: <strong>12345678</strong>.</li>
  <li>Open a browser and go to <strong>http://192.168.4.1</strong>.</li>
  <li>The setup screen should appear.</li>
</ol>

<p>
  From the setup screen, you can either connect the controller to a home WiFi network or keep it in standalone mode.
</p>

<hr>

<h2 id="connecting-to-wifi">Connecting to WiFi</h2>

<p>
  Connecting the controller to home WiFi allows you to open the control page from any device on the same local network.
</p>

<h3>WiFi Setup Steps</h3>

<ol>
  <li>Connect to the <strong>BirdFeeder Setup</strong> WiFi network.</li>
  <li>Open <strong>http://192.168.4.1</strong>.</li>
  <li>Click or tap <strong>Scan for WiFi</strong>.</li>
  <li>Select your WiFi network from the list, or type the WiFi name manually.</li>
  <li>Enter the WiFi password.</li>
  <li>Confirm the local device name. The default is <strong>birdfeeder</strong>.</li>
  <li>Click or tap <strong>Connect to WiFi</strong>.</li>
  <li>Wait for the controller to connect.</li>
  <li>Open <strong>http://birdfeeder.local</strong> from a device on the same WiFi network.</li>
</ol>

<h3>About the Local Name</h3>

<p>
  The default local address is:
</p>

<pre><code>http://birdfeeder.local</code></pre>

<p>
  If the local name is changed during setup, use the new name followed by <strong>.local</strong>. For example, if the device name is changed to <strong>garage-feeder</strong>, the local address becomes:
</p>

<pre><code>http://garage-feeder.local</code></pre>

<p>
  The local name is cleaned automatically by the controller. Spaces are converted to hyphens, unsupported characters are removed, and very long names are shortened.
</p>

<hr>

<h2 id="using-standalone-mode">Using Standalone Mode</h2>

<p>
  Standalone mode is used when the controller should not connect to home WiFi, or when no home WiFi is available.
</p>

<p>
  In standalone mode:
</p>

<ul>
  <li>The controller continues broadcasting <strong>BirdFeeder Setup</strong>.</li>
  <li>Users connect directly to the controller's WiFi network.</li>
  <li>The control page is opened at <strong>http://192.168.4.1</strong>.</li>
  <li>The controller does not need internet access.</li>
</ul>

<h3>When to Use Standalone Mode</h3>

<ul>
  <li>The feeder is installed somewhere without reliable WiFi.</li>
  <li>You do not want the device connected to your home network.</li>
  <li>You are testing the controller before final installation.</li>
  <li>You are troubleshooting WiFi connection issues.</li>
</ul>

<hr>

<h2 id="opening-the-control-page">Opening the Control Page</h2>

<table>
  <thead>
    <tr>
      <th align="left">Connection Method</th>
      <th align="left">Address to Open</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Connected directly to <strong>BirdFeeder Setup</strong></td>
      <td><strong>http://192.168.4.1</strong></td>
    </tr>
    <tr>
      <td>Controller connected to home WiFi</td>
      <td><strong>http://birdfeeder.local</strong></td>
    </tr>
    <tr>
      <td>Controller connected to home WiFi with custom name</td>
      <td><strong>http://your-device-name.local</strong></td>
    </tr>
    <tr>
      <td>mDNS not working</td>
      <td>Use the IP address shown on the setup or settings page.</td>
    </tr>
  </tbody>
</table>

<p>
  The controller hosts the page itself. No cloud service, app store download, or internet connection is required for normal local operation.
</p>

<hr>

<h2 id="main-control-page">Main Control Page</h2>

<p>
  The main control page is intended for daily use. It provides simple controls and live status feedback.
</p>

<h3>Motor On / Off</h3>

<p>
  The large motor button starts or stops the feeder motor. When the motor is running, the button shows <strong>ON</strong>. When the motor is stopped, it shows <strong>OFF</strong>.
</p>

<h3>Direction</h3>

<p>
  The direction control allows the motor to run in <strong>Forward</strong> or <strong>Reverse</strong>. The firmware is configured so the displayed forward direction matches the current board and motor wiring.
</p>

<h3>Speed Control</h3>

<p>
  The controller supports two speed-control modes:
</p>

<table>
  <thead>
    <tr>
      <th align="left">Mode</th>
      <th align="left">Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Physical Knob</td>
      <td>The speed is controlled by the onboard potentiometer.</td>
    </tr>
    <tr>
      <td>App Slider</td>
      <td>The speed is controlled from the browser page.</td>
    </tr>
  </tbody>
</table>

<p>
  If <strong>Physical Knob</strong> is selected, the app slider is ignored. If <strong>App Slider</strong> is selected, the physical knob is ignored.
</p>

<h3>Sensor Indicators</h3>

<p>
  The control page includes two live sensor indicators:
</p>

<ul>
  <li><strong>Break Beam</strong>: Shows whether the beam is clear or blocked.</li>
  <li><strong>Jam / StallGuard</strong>: Shows whether the feeder is OK or has detected a jam.</li>
</ul>

<h3>Current Status</h3>

<p>
  The status area shows useful operating information, including:
</p>

<ul>
  <li>Speed source.</li>
  <li>Commanded speed percentage.</li>
  <li>Physical knob speed percentage.</li>
  <li>Current step frequency.</li>
  <li>Home WiFi IP address.</li>
  <li>Stop reason.</li>
  <li>Power-good state.</li>
</ul>

<hr>

<h2 id="mode-button-operation">Mode Button Operation</h2>

<p>
  The physical mode button provides basic local control without opening the web interface.
</p>

<table>
  <thead>
    <tr>
      <th align="left">Button Action</th>
      <th align="left">Result</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Single press</td>
      <td>Starts or stops the motor.</td>
    </tr>
    <tr>
      <td>Double press</td>
      <td>Reverses motor direction.</td>
    </tr>
  </tbody>
</table>

<p>
  The button uses debounce logic so brief electrical noise should not trigger false presses. A double press must happen quickly enough to be detected as a double press instead of two separate single presses.
</p>

<hr>

<h2 id="break-beam-sensor">Break-Beam Sensor</h2>

<p>
  The break-beam sensor is used to stop the motor when the beam is blocked. This may be used to detect an obstruction, a feeder position, or another mechanical condition depending on the final product design.
</p>

<h3>How It Works</h3>

<ul>
  <li>The firmware assumes the break-beam input reads <strong>LOW</strong> when blocked.</li>
  <li>If the motor is running and the beam becomes blocked, the motor stops immediately.</li>
  <li>The stop reason changes to <strong>Stopped: breakbeam blocked</strong>.</li>
  <li>The break-beam indicator turns red in the web interface.</li>
  <li>The break-beam LED turns on.</li>
</ul>

<h3>Automatic Resume</h3>

<p>
  If the motor was running and is stopped by the break beam, the controller remembers that the stop was caused by the beam. When the beam clears, the motor automatically resumes.
</p>

<p>
  The motor does <strong>not</strong> automatically resume after a user stop or jam stop.
</p>

<table>
  <thead>
    <tr>
      <th align="left">Stop Cause</th>
      <th align="left">Auto-Resume?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>User pressed stop</td>
      <td>No</td>
    </tr>
    <tr>
      <td>Break beam blocked while running</td>
      <td>Yes, after the beam clears</td>
    </tr>
    <tr>
      <td>Jam / StallGuard trip</td>
      <td>No</td>
    </tr>
  </tbody>
</table>

<hr>

<h2 id="jam-detection-stallguard">Jam Detection / StallGuard</h2>

<p>
  The controller uses the TMC2209 stepper driver's StallGuard feedback to help detect feeder jams. StallGuard estimates motor load without requiring a separate mechanical switch. When the measured value indicates a likely jam for long enough, the firmware stops the motor and reports a jam fault.
</p>

<h3>Important Behavior</h3>

<ul>
  <li>Jam detection can be enabled or disabled from the settings page.</li>
  <li>The firmware ignores StallGuard briefly after the motor starts, so startup load does not immediately trigger a jam.</li>
  <li>StallGuard is ignored below the configured minimum detection speed.</li>
  <li>The controller uses different trip thresholds for low, mid, and high speed ranges.</li>
  <li>A jam must remain active for the configured confirmation time before the motor stops.</li>
</ul>

<h3>Why StallGuard Needs Tuning</h3>

<p>
  StallGuard readings depend on the motor, feeder load, step speed, current, supply voltage, and mechanical friction. A threshold that works well on one feeder may be too sensitive or not sensitive enough on another. For this reason, the controller includes both manual tuning fields and a calibration helper.
</p>

<h3>What Happens During a Jam Stop</h3>

<ul>
  <li>The motor stops.</li>
  <li>The stop reason changes to <strong>Stopped: jam / StallGuard</strong>.</li>
  <li>The jam indicator turns red in the web interface.</li>
  <li>The jam LED turns on.</li>
  <li>The motor does not automatically restart.</li>
</ul>

<p>
  After clearing the jam, start the motor again from the web page or with the mode button.
</p>

<hr>

<h2 id="motor-tuning-settings">Motor Tuning Settings</h2>

<p>
  Motor tuning settings are available on the settings page. These settings are saved in non-volatile memory so they remain after a reboot or firmware update.
</p>

<h3>Default Motor Settings</h3>

<table>
  <thead>
    <tr>
      <th align="left">Setting</th>
      <th align="left">Default</th>
      <th align="left">Purpose</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Min STEP Speed</td>
      <td>25 Hz</td>
      <td>Lowest step frequency used when speed is above 0%.</td>
    </tr>
    <tr>
      <td>Max STEP Speed</td>
      <td>375 Hz</td>
      <td>Highest step frequency at 100% speed.</td>
    </tr>
    <tr>
      <td>Acceleration</td>
      <td>4000 steps/s²</td>
      <td>How quickly the motor ramps speed.</td>
    </tr>
    <tr>
      <td>StallGuard Trip Confirm</td>
      <td>50 ms</td>
      <td>How long a jam condition must remain active before stopping.</td>
    </tr>
    <tr>
      <td>StallGuard Sensitivity SGTHRS</td>
      <td>25</td>
      <td>TMC2209 StallGuard sensitivity setting.</td>
    </tr>
    <tr>
      <td>Minimum SG Detect Speed</td>
      <td>100 Hz</td>
      <td>Below this speed, StallGuard detection is ignored.</td>
    </tr>
    <tr>
      <td>Low Speed Trip Below</td>
      <td>2</td>
      <td>Trip threshold near the low-speed range.</td>
    </tr>
    <tr>
      <td>Mid Speed Trip Below</td>
      <td>5</td>
      <td>Trip threshold near the mid-speed range.</td>
    </tr>
    <tr>
      <td>High Speed Trip Below</td>
      <td>20</td>
      <td>Trip threshold near the high-speed range.</td>
    </tr>
  </tbody>
</table>

<h3>General Tuning Guidance</h3>

<ul>
  <li>Do not increase sensitivity just to hide a mechanical problem.</li>
  <li>If false jams happen at high speed, reduce the high-speed trip threshold or increase the confirmation time slightly.</li>
  <li>If real jams are not detected, increase the appropriate trip threshold for the speed range being used.</li>
  <li>If jams happen during startup, increase the startup ignore time.</li>
  <li>If StallGuard behaves inconsistently at very low speed, increase the minimum SG detect speed.</li>
</ul>

<hr>

<h2 id="stallguard-calibration">StallGuard Calibration</h2>

<p>
  The settings page includes a calibration helper that measures StallGuard during free spinning and then during a controlled jam or drag condition. The controller uses those two readings to calculate a practical trip threshold.
</p>

<h3>Calibration Steps</h3>

<ol>
  <li>Open the settings page.</li>
  <li>Temporarily disable <strong>StallGuard Monitor</strong> if it is stopping too quickly during testing.</li>
  <li>Start the motor.</li>
  <li>Set the speed to the range you actually plan to use.</li>
  <li>Let the feeder spin freely.</li>
  <li>Click <strong>1. Capture Free Spin</strong>.</li>
  <li>Lightly jam, drag, or load the feeder in a controlled way.</li>
  <li>Click <strong>2. Capture Jam &amp; Apply</strong>.</li>
  <li>Save or verify the applied settings.</li>
  <li>Re-enable <strong>StallGuard Monitor</strong> if it was disabled.</li>
  <li>Test normal feeding and a controlled jam again.</li>
</ol>

<h3>Calibration Notes</h3>

<ul>
  <li>Calibrate at the speed range you expect to use most often.</li>
  <li>Do not use excessive force when creating a jam sample.</li>
  <li>If the jam reading does not drop compared to the free-spin reading, the controller applies a conservative fallback threshold.</li>
  <li>Repeat calibration if the motor, feeder mechanics, power supply, or operating speed changes significantly.</li>
</ul>

<hr>

<h2 id="settings-and-diagnostics-page">Settings and Diagnostics Page</h2>

<p>
  The settings page provides WiFi settings, motor tuning, StallGuard calibration, firmware updates, live diagnostics, and the device log.
</p>

<h3>WiFi Setup Section</h3>

<ul>
  <li>Change the saved WiFi network.</li>
  <li>Change the local device name.</li>
  <li>Switch to standalone mode.</li>
  <li>Forget the saved WiFi network.</li>
</ul>

<h3>Motor Tuning Section</h3>

<ul>
  <li>Set minimum and maximum step speed.</li>
  <li>Set acceleration.</li>
  <li>Enable or disable StallGuard monitoring.</li>
  <li>Adjust StallGuard sensitivity and trip thresholds.</li>
</ul>

<h3>Diagnostics Section</h3>

<p>
  The diagnostics section shows live technical information that can help during setup and support:
</p>

<ul>
  <li>Firmware version.</li>
  <li>Uptime.</li>
  <li>Home WiFi IP address.</li>
  <li>Setup network IP address.</li>
  <li>Free heap memory.</li>
  <li>PSRAM size.</li>
  <li>Raw potentiometer value.</li>
  <li>Current STEP frequency.</li>
  <li>Raw DIAG pin state.</li>
  <li>StallGuard state.</li>
  <li>TMC UART communication status.</li>
  <li>Current SG_RESULT value.</li>
  <li>Dynamic StallGuard trip threshold.</li>
  <li>Physical knob speed percentage.</li>
</ul>

<h3>Device Log</h3>

<p>
  The device log records useful events, including boot messages, WiFi connection attempts, motor start/stop events, direction changes, StallGuard calibration samples, OTA update events, and errors. The log is especially useful when contacting support.
</p>

<hr>

<h2 id="firmware-updates">Firmware Updates</h2>

<p>
  Firmware updates can be uploaded from the settings page using a compiled <strong>.bin</strong> firmware file.
</p>

<h3>Update Steps</h3>

<ol>
  <li>Open the settings page.</li>
  <li>Find the <strong>Firmware Update</strong> section.</li>
  <li>Select the provided <strong>.bin</strong> firmware file.</li>
  <li>Click <strong>Upload Firmware</strong>.</li>
  <li>Wait for the upload to finish.</li>
  <li>The controller will reboot automatically after a successful update.</li>
  <li>Reconnect to the controller if the browser does not reconnect automatically.</li>
</ol>

<h3>Firmware Update Notes</h3>

<ul>
  <li>The motor is stopped before the firmware update begins.</li>
  <li>Saved WiFi and tuning settings are normally retained through firmware updates.</li>
  <li>Do not remove power during an update.</li>
  <li>If the update fails, try again while connected directly to the controller's setup network.</li>
</ul>

<hr>

<h2 id="resetting-onboarding">Resetting Onboarding</h2>

<p>
  The onboarding popup can be reset by opening this path in a browser:
</p>

<pre><code>http://birdfeeder.local/api/resetOnboarding</code></pre>

<p>
  Or, when connected directly to the setup network:
</p>

<pre><code>http://192.168.4.1/api/resetOnboarding</code></pre>

<p>
  After onboarding is reset, reload the main page. The welcome/setup popup should appear again.
</p>

<hr>

<h2 id="troubleshooting">Troubleshooting</h2>

<h3>The setup WiFi network does not appear</h3>

<ul>
  <li>Confirm the controller is powered.</li>
  <li>Wait at least 10 seconds after applying power.</li>
  <li>Move closer to the controller.</li>
  <li>Restart the controller.</li>
  <li>Check that your phone or computer is not filtering or hiding 2.4 GHz networks.</li>
</ul>

<h3>I connected to BirdFeeder Setup but the page does not open</h3>

<ul>
  <li>Open <strong>http://192.168.4.1</strong> manually.</li>
  <li>Make sure your device stayed connected to <strong>BirdFeeder Setup</strong>.</li>
  <li>Turn off mobile data temporarily if your phone keeps trying to use cellular internet.</li>
  <li>Try another browser.</li>
  <li>Restart the controller.</li>
</ul>

<h3>birdfeeder.local does not open</h3>

<ul>
  <li>Make sure the controller successfully connected to home WiFi.</li>
  <li>Make sure your phone or computer is on the same WiFi network.</li>
  <li>Try the controller's IP address shown on the settings page.</li>
  <li>Try <strong>http://birdfeeder.local</strong> instead of <strong>https://birdfeeder.local</strong>.</li>
  <li>Some routers or devices do not handle <strong>.local</strong> names reliably. Use the IP address if needed.</li>
</ul>

<h3>The controller will not connect to home WiFi</h3>

<ul>
  <li>Check the WiFi password carefully.</li>
  <li>Use a 2.4 GHz WiFi network if your router separates 2.4 GHz and 5 GHz bands.</li>
  <li>Move the controller closer to the router during setup.</li>
  <li>Avoid hidden SSIDs during first setup if possible.</li>
  <li>Use standalone mode if the location does not have reliable WiFi.</li>
</ul>

<h3>The motor does not start</h3>

<ul>
  <li>Check whether the break-beam indicator says <strong>Blocked</strong>.</li>
  <li>Check whether the jam indicator says <strong>Jammed</strong>.</li>
  <li>Check the stop reason on the control page.</li>
  <li>Confirm the power-good indicator says ready.</li>
  <li>Check the motor wiring and power supply.</li>
  <li>Open the settings page and check whether the TMC UART status is OK.</li>
</ul>

<h3>The motor runs the wrong direction</h3>

<ul>
  <li>Use the direction buttons on the control page.</li>
  <li>Double-press the mode button to reverse direction.</li>
  <li>If the labels appear backwards after wiring changes, the motor wiring or firmware direction setting may need to be updated.</li>
</ul>

<h3>The motor stops whenever I turn the speed up</h3>

<ul>
  <li>Check whether the stop reason is <strong>Stopped: jam / StallGuard</strong>.</li>
  <li>If yes, StallGuard is probably too sensitive for that speed range.</li>
  <li>Reduce the high-speed trip threshold or increase the trip confirmation time.</li>
  <li>Run the StallGuard calibration at the speed where the issue occurs.</li>
  <li>Inspect the feeder for real mechanical drag before reducing protection.</li>
</ul>

<h3>The motor stops when the break beam is blocked</h3>

<p>
  This is expected behavior. If the motor was running when the beam became blocked, it should automatically resume after the beam clears.
</p>

<p>
  If this behavior is not desired for a specific installation, the firmware behavior would need to be changed.
</p>

<h3>The break-beam indicator is backwards</h3>

<p>
  The firmware assumes the break-beam input reads <strong>LOW</strong> when blocked. If your sensor outputs the opposite signal, the sensor wiring or firmware logic must be changed.
</p>

<h3>The jam indicator stays red</h3>

<ul>
  <li>Clear any mechanical jam.</li>
  <li>Stop and restart the motor.</li>
  <li>Check the raw DIAG pin state on the settings page.</li>
  <li>Check TMC UART communication status.</li>
  <li>Temporarily disable StallGuard Monitor to confirm the motor and feeder work mechanically.</li>
  <li>Recalibrate StallGuard before normal use.</li>
</ul>

<h3>TMC UART shows failed</h3>

<ul>
  <li>Power-cycle the controller and check again.</li>
  <li>Confirm the motor driver is installed and powered correctly.</li>
  <li>Check RX/TX wiring between the ESP32-S3 and TMC2209.</li>
  <li>Check that MS1 and MS2 address pins are configured for address 0.</li>
  <li>If UART remains failed, basic STEP/DIR motor control may still work, but SG_RESULT-based calibration will not work.</li>
</ul>

<h3>The firmware update page fails</h3>

<ul>
  <li>Confirm you selected the correct <strong>.bin</strong> file.</li>
  <li>Try again while connected directly to <strong>BirdFeeder Setup</strong>.</li>
  <li>Do not refresh the page during upload.</li>
  <li>Do not remove power during upload.</li>
  <li>Restart the controller and try again.</li>
</ul>

<hr>

<h2 id="technical-reference">Technical Reference</h2>

<h3>Default Network Information</h3>

<table>
  <thead>
    <tr>
      <th align="left">Item</th>
      <th align="left">Default</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Setup WiFi Name</td>
      <td>BirdFeeder Setup</td>
    </tr>
    <tr>
      <td>Setup WiFi Password</td>
      <td>12345678</td>
    </tr>
    <tr>
      <td>Standalone Address</td>
      <td>http://192.168.4.1</td>
    </tr>
    <tr>
      <td>Default Local Address</td>
      <td>http://birdfeeder.local</td>
    </tr>
    <tr>
      <td>Default Hostname</td>
      <td>birdfeeder</td>
    </tr>
  </tbody>
</table>

<h3>Firmware Version</h3>

<p>
  The firmware version is shown on the settings page. The referenced firmware version for this document is:
</p>

<pre><code>1.0.15 - 05.11.2026</code></pre>

<h3>Saved Settings</h3>

<p>
  The controller saves configuration in non-volatile memory. The following settings are retained after reboot:
</p>

<ul>
  <li>WiFi name and password.</li>
  <li>Local hostname.</li>
  <li>Onboarding status.</li>
  <li>Standalone mode setting.</li>
  <li>Physical knob vs. app slider speed mode.</li>
  <li>Manual app slider speed.</li>
  <li>Direction setting.</li>
  <li>Light or dark theme.</li>
  <li>Minimum and maximum motor step speed.</li>
  <li>Acceleration.</li>
  <li>StallGuard enable setting.</li>
  <li>StallGuard sensitivity and threshold values.</li>
</ul>

<h3>Primary GPIO Map</h3>

<p>
  GPIO numbers are listed for technical reference. These are ESP32 GPIO numbers, not physical connector pin numbers.
</p>

<table>
  <thead>
    <tr>
      <th align="left">Function</th>
      <th align="left">GPIO</th>
    </tr>
  </thead>
  <tbody>
    <tr><td>Speed Control Potentiometer</td><td>7</td></tr>
    <tr><td>TMC RX</td><td>15</td></tr>
    <tr><td>TMC TX</td><td>16</td></tr>
    <tr><td>Direction</td><td>17</td></tr>
    <tr><td>TMC DIAG</td><td>18</td></tr>
    <tr><td>I2C SDA</td><td>8</td></tr>
    <tr><td>I2C SCL</td><td>9</td></tr>
    <tr><td>TMC Enable</td><td>10</td></tr>
    <tr><td>Status LED 1</td><td>11</td></tr>
    <tr><td>Status LED 2</td><td>12</td></tr>
    <tr><td>Status LED 3</td><td>13</td></tr>
    <tr><td>STEP</td><td>14</td></tr>
    <tr><td>Index Input</td><td>21</td></tr>
    <tr><td>Boot Button</td><td>0</td></tr>
    <tr><td>Break-Beam Input</td><td>39</td></tr>
    <tr><td>Spare 3.3V Sensor Input</td><td>40</td></tr>
    <tr><td>5V Sensor Input 1</td><td>41</td></tr>
    <tr><td>5V Sensor Input 2</td><td>42</td></tr>
    <tr><td>TMC MS1</td><td>2</td></tr>
    <tr><td>TMC MS2</td><td>1</td></tr>
    <tr><td>Mode Button</td><td>5</td></tr>
    <tr><td>CH224K Power Good</td><td>3</td></tr>
    <tr><td>USB D-</td><td>19</td></tr>
    <tr><td>USB D+</td><td>20</td></tr>
  </tbody>
</table>

<h3>Useful Local API Paths</h3>

<p>
  These paths are used by the web interface and may also be useful for support or testing on a local network.
</p>

<table>
  <thead>
    <tr>
      <th align="left">Path</th>
      <th align="left">Purpose</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>/</code></td>
      <td>Main control page.</td>
    </tr>
    <tr>
      <td><code>/settings</code></td>
      <td>Settings, diagnostics, calibration, and firmware update page.</td>
    </tr>
    <tr>
      <td><code>/api/status</code></td>
      <td>Returns live device status as JSON.</td>
    </tr>
    <tr>
      <td><code>/api/resetOnboarding</code></td>
      <td>Resets the onboarding popup.</td>
    </tr>
    <tr>
      <td><code>/api/reboot</code></td>
      <td>Reboots the controller.</td>
    </tr>
  </tbody>
</table>

<p>
  These endpoints are intended for local device operation and support. They should not be exposed directly to the public internet.
</p>

<hr>

<h2 id="support-information-to-provide">Support Information to Provide</h2>

<p>
  If you need help, provide as much of the following information as possible:
</p>

<ul>
  <li>Firmware version shown on the settings page.</li>
  <li>Whether you are using home WiFi or standalone mode.</li>
  <li>The stop reason shown on the control page.</li>
  <li>Whether the break-beam indicator says clear or blocked.</li>
  <li>Whether the jam indicator says OK or jammed.</li>
  <li>Current step frequency.</li>
  <li>Knob speed percentage or app slider percentage.</li>
  <li>TMC UART status.</li>
  <li>SG_RESULT and dynamic trip value.</li>
  <li>A copy or screenshot of the device log.</li>
  <li>A description of what the feeder was doing when the issue happened.</li>
</ul>


