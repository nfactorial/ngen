/**
 * Represents a server machine within the network.
 * Each server is a virtual machine instance dedicated to hosting a number of
 * sessions.
 * This class manages the lifetime of each virtual machine, when a virtual machine
 * is started, this class keeps polling the instance to detect when it is ready for
 * use. The VM is also supplied a communication port that it may connect to
 */
class Server {
    constructor() {
        this.name = '';         // Name of this server virtual machine
        this.sessions = [];     // List of active sessions
        this.lastSeen = 0;      // When did we last hear from this machine?
        this.status = Server.STATUS_TERMINATED;
    }

    /**
     * Starts the server and brings up a virtual machine if necessasry.
     */
    start() {
        if ( this.status != Server.STATUS_TERMINATED ) {
            throw new Error( 'Server::start - Cannot start server, server is already created.' );
        }

        this.atatus = Server.STATUS_STARTING;
        this.lastSeen = Date.now();

        // TODO: Create listen socket for the server to connect to once it is ready.
    }

    /**
     * Called every keep-alive interval to make sure the server is still communicating
     * with us regularly.
     */
    manageLifetime() {
        switch ( this.status ) {
            case Server.STATUS_TERMINATED:
                // This server is not alive
                break;

            case Server.STATUS_STARTING_VM:
                // Ask azure about the servers status, is it still progressing?
                break;

            case Server.STATUS_STARTING_PROCESS:
                // We're waiting for the server process to begin communication
                // is it taking too long?
                break;

            case Server.STATUS_ACTIVE:
                // Server is active, make sure we received a keep alive recently
                break;
        }
    }
}


Server.STATUS_TERMINATED        = 0;    // VM has not been created
Server.STATUS_STARTING_VM       = 1;    // Currently waiting for VM to start
Server.STATUS_STARTING_PROCESS  = 2;    // Waiting for instance to begin communication
Server.STATUS_ACTIVE            = 3;    // Server is up and running
