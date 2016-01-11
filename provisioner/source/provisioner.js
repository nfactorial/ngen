

class ServerProvisioner {
    consructor() {
        this.activeServers = [];
        this.maximumSessions= ServerProvisioner.DEFAULT_SERVER_SESSIONS;
        this.minimumServers = ServerProvisioner.DEFAULT_MINIMUM_SERVERS;
        this.maximumServers = ServerProvisioner.DEFAULT_MAXIMUM_SERVERS;
        this.keepAliveTimer = null;     // Timer used to check for dead servers
    }

    allocateServer() {
        // Once we've successfully requested a VM to begin life, we must
        // start checking for it to successfully start.
        var self = this;
        this.timeout = setTimeout( function() {
            self.manageLifetime();
        })
    }
}

ServerProvisioner.DEFAULT_SERVER_SESSIONS = 4;
ServerProvisioner.DEFAULT_MAXIMUM_SERVERS = 1;
ServerProvisioner.DEFAULT_MINIMUM_SERVERS = 0;
