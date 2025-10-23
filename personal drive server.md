Howdy!

Did you know I spent yesterday (October 22, 2025) trying to figure out how to set up [PiVPN](https://github.com/pivpn/pivpn) with [WireGuard](https://www.wireguard.com/)? Well no, you aren't supposed to because that would be pretty weird.

But I did, and I installed it on my Pi5 that I have and I haven't been using (since no one wants to play minecraft I guess); but even in the case of minecraft, I likely wouldn't have been able to host a minecraft server beyond my local IP.


First, I should explain why I decided to make a server. For me, I personally hate it when files on my main PC (school, etc.) aren't on my laptop which I use about 80% of the time anyway. So, then I'd have to get my giant USB cable and plug them in, realize that doesn't work, and then get a USB drive and just move things over that way. And don't get me started about getting files from my phone; the USB-C port is pretty messed up and it can barely keep a connection, and we know how slow file transfer is over bluetooth.

In the past, I thought about maybe setting up my PC to somehow remotely get things over with SSH and X11 or WoL (Wake-on-LAN) and just be able to use my PC away, but I realize how tedious that would feel to use and setup (because I tried and I couldn't get it to work).

It was only until now I felt it was necessary to perhaps use my PI for good, and that would be as a small, de-googled drive.


As I said, I initially got PiVPN, but before that I got a Docker instance and setup file browser and I eventually got it working where I could access it through my web browser after some trial and error and getting log errors about not being able to create a file. Turns out, I had to delete previously generated filepaths and also make sure that in the docker-compose it all pointed properly. Eventually it was running all fine and dandy.

Then I wanted to be able to somehow access it outside of my local network. So, I got PiVPN and gave that a whirl with WireGuard. It was a lot of setting up, getting a [DuckDNS](https://www.duckdns.org/) domain since it makes accessing the IP easier and I wasn't sure if my WIFI was static or not since it's an apartment where I can't even access the router or its settings.

And that brings me to why I think nothing was working for the PiVPN, which I was able to connect to from my phone, but I couldn't access webpages or anything. I couldn't even check my IP to verify the VPN was working since I couldn't even boot up whatismyipaddress.com (though, I realize now there was probably an easier way to check the IP through my android's settings or just believing what the WireGuard app said). With that, the root cause was, I think, from not being able to enable Port Forwarding in the router settings for the standard port of 51820.

Then, ~~I was at a loss. No matter how hard I tried I could just never seem to get it to work~~ I used [Tailscale](https://tailscale.com/). It took me, I kid you not, like 5 minutes and everything was working.

Today (October 23, 2025), I went out to class and I was laughing maniacally in the hallway for my lab when I typed in the IP and port of my PI via Tailscale and saw the filemanager login screen. I logged in and... man... it's that same feeling you get after wondering why your code doesn't work at all and you forgot a semicolon or it was j++ instead of ++j or something stupid.


Now, I feel all powerful. I could get other services besides file browser to run through it. Honestly, if I had the budget, I would love to make a PI 5 NAS to run OpenMediaVault or something else when I'm on the go. Maybe Jellyfin could work, too! There are just too many possibilities for me to run through here.

I finally did something I never thought I could do, and I am proud of myself. Though, I still have to research more to see how secure tailscale and this setup truly is since, when it comes to servers, that's usually the sticking point.
