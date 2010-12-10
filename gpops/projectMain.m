clear setup limits guess CONSTANTS

global CONSTANTS

CONSTANTS.g = 9.80665;
CONSTANTS.m = 1450;
CONSTANTS.Iz = 2740;
CONSTANTS.lF = 1.1;
CONSTANTS.lR = 1.6;
CONSTANTS.B = 7;
CONSTANTS.C = 1.4;
CONSTANTS.mu = 0.5;

CONSTANTS.fFz = CONSTANTS.m*CONSTANTS.g*CONSTANTS.lR/(CONSTANTS.lF+CONSTANTS.lR);
CONSTANTS.fRz = CONSTANTS.m*CONSTANTS.g*CONSTANTS.lF/(CONSTANTS.lF+CONSTANTS.lR);

CONSTANTS.fFxmax = CONSTANTS.mu*CONSTANTS.fFz;
CONSTANTS.fRxmax = CONSTANTS.mu*CONSTANTS.fRz;

Vx0 = 55000/3600;
Vxf = 0;
Vy0 = 0;
psi0 = 0;
psif = pi/2;
r0 = 0;
rf = 0;
X0 = 0;
Y0 = 0;

Vxmin = -Vx0*1.5;
Vxmax = Vx0*1.5;
Vymin = -Vx0*1.5;
Vymax = Vx0*1.5;
psimin = -pi/3;
psimax = 2*pi/3;
rmin = -3;
rmax = 10;
Xmax = 300;
Xmin = -10;
Ymax = 50;
Ymin = -20;
fFxmin = -CONSTANTS.fFxmax;
fFxmax = 0;
fRxmin = -CONSTANTS.fRxmax;
fRxmax = CONSTANTS.fRxmax;
deltamin = -pi/4;
deltamax = pi/4;
t0min = 0;
t0max = 0;
tfmin = 0;
tfmax = 10;
tfend = 1;

% Phase 1 Information
iphase = 1;
limits(iphase).nodes            = 21;
limits(iphase).time.min         = [t0min tfmin];
limits(iphase).time.max         = [t0max tfmax];
limits(iphase).state.min(1,:)   = [Vx0 Vxmin Vxf];
limits(iphase).state.max(1,:)   = [Vx0 Vxmax Vxf];
limits(iphase).state.min(2,:)   = [Vy0 Vymin Vymin];
limits(iphase).state.max(2,:)   = [Vy0 Vymax Vymax];
limits(iphase).state.min(3,:)   = [psi0 psimin psif];
limits(iphase).state.max(3,:)   = [psi0 psimax psif];
limits(iphase).state.min(4,:)   = [r0 rmin rf];
limits(iphase).state.max(4,:)   = [r0 rmax rf];
limits(iphase).state.min(5,:)   = [X0 Xmin Xmin];
limits(iphase).state.max(5,:)   = [X0 Xmax Xmax];
limits(iphase).state.min(6,:)   = [Y0 Ymin Ymin];
limits(iphase).state.max(6,:)   = [Y0 Ymax Ymax];
limits(iphase).control.min(1,:) = fFxmin;
limits(iphase).control.max(1,:) = fFxmax;
limits(iphase).control.min(2,:) = fRxmin;
limits(iphase).control.max(2,:) = fRxmax;
limits(iphase).control.min(3,:) = deltamin;
limits(iphase).control.max(3,:) = deltamax;
limits(iphase).parameter.min    = [];
limits(iphase).parameter.max    = [];
limits(iphase).path.min         = [];
limits(iphase).path.max         = [];
limits(iphase).event.min        = [];
limits(iphase).event.max        = [];
limits(iphase).duration.min     = [];
limits(iphase).duration.max     = [];
guess(iphase).time              = [t0min; tfend];
guess(iphase).state(:,1)        = [Vx0; Vxf];
guess(iphase).state(:,2)        = [Vy0; Vxf*0.5];
guess(iphase).state(:,3)        = [psi0; psif];
guess(iphase).state(:,4)        = [r0; rf];
guess(iphase).state(:,5)        = [X0; Xmax];
guess(iphase).state(:,6)        = [Y0; Y0];
guess(iphase).control(:,1)      = [0; 0];
guess(iphase).control(:,2)      = [0; 0];
guess(iphase).control(:,3)      = [0; 0];
guess(iphase).parameter         = [];

linkages = [];
setup.name  = 'project';
setup.funcs.cost = 'projectCost';
setup.funcs.dae = 'projectDae';
setup.limits = limits;
setup.guess = guess;
setup.linkages = linkages;
setup.derivatives = 'complex';
setup.direction = 'increasing';
setup.autoscale = 'off';

output = gpops(setup);
solution = output.solution;

Vx = solution.state(:,1);
Vy = solution.state(:,2);
fFx = solution.control(:,1);
fRx = solution.control(:,2);
delta = solution.control(:,3);

VF = abs(sign(Vx.*cos(delta)+Vy.*sin(delta)));
VR = abs(sign(Vx));
fFx(fFx < 0) = fFx(fFx < 0) .* VF(fFx < 0);
fRx(fRx < 0) = fRx(fRx < 0) .* VR(fRx < 0);

figure(1);
plot(solution.state(:,5), solution.state(:,6)); % X,Y plane
title('Trajectory of Vehicle in X-Y plane');
xlabel('X (m)');
ylabel('Y (m)');

figure(2);
subplot(1,3,1);
plot(solution.time, fFx);
title('Front Tire Force Control Input');
xlabel('Time (s)');
ylabel('f_{Rx} (N)');
subplot(1,3,2);
plot(solution.time, fRx);
title('Rear Tire Force Control Input');
xlabel('Time (s)');
ylabel('f_{Fx} (N)');
subplot(1,3,3);
plot(solution.time, solution.control(:,3)*180/pi);
title('Steering Angle Control Input');
xlabel('Time (s)');
ylabel('\delta (deg)');

figure(3);
plot(solution.time, solution.state(:,3)*180/pi);
title('Vehicle direction');
xlabel('Time (s)');
ylabel('\psi (deg)');

figure(4);
subplot(1,2,1);
plot(solution.time, solution.state(:,1));
title('Velocity in the x direction');
xlabel('Time (s)');
ylabel('V_{x} (m/s)');
subplot(1,2,2);
plot(solution.time, solution.state(:,2));
title('Velocity in the y direction');
xlabel('Time (s)');
ylabel('V_{y} (m/s)');

figure(5);
plot(solution.time, solution.Hamiltonian);
title('Hamiltonian');
xlabel('Time (s)');
ylabel('H');

figure(6);
subplot(1,3,1);
plot(solution.time, solution.control_pontryagin(:,1));
title('Front Tire Force Control Input');
xlabel('Time (s)');
ylabel('f_{Rx} (N)');
subplot(1,3,2);
plot(solution.time, solution.control_pontryagin(:,2));
title('Rear Tire Force Control Input');
xlabel('Time (s)');
ylabel('f_{Fx} (N)');
subplot(1,3,3);
plot(solution.time, solution.control_pontryagin(:,3)*180/pi);
title('Steering Angle Control Input');
xlabel('Time (s)');
ylabel('\delta (deg)');

figure(7);
plot(solution.time, solution.state(:,4)*180/pi);
title('Vehicle angular velocity');
xlabel('Time (s)');
ylabel('r (deg/s)');

% subplot(1,3,sn);
% plot(solution.time, solution.control);
% title(['x_0 = ' num2str(x0)]);
% xlabel('Time (s)');
% ylabel('Control u');
% drawnow;