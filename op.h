
typedef struct signat {
	void (*fp)();
	int in;
	unsigned t;
	int out;
} signat;

typedef struct oper {
	unsigned name;
	int n;
	unsigned sigadr;
} oper;

enum typepat { anytype = stringtype + 1,
	floattype, numbertype, proctype };

#define MAXOPS 40
#define SDSIZE 30

void initoptab(context *ctx);

object consoper(context *ctx, char *name, void (*fp)(), int out, int in, ...);

void opexec(context *ctx, unsigned opcode);

#define INSTALL \
	n.tag = nametype, \
	n.mark_.padw = optab[op.mark_.padw].name, \
	bdcput(ctx, sd, n, op), \
	optab = (void *)(ctx->gl->base + adrent(ctx->gl, OPTAB)); // recalc

void initop(context *ctx);

