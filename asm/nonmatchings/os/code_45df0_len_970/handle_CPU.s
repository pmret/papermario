.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel handle_CPU
/* 46438 8006B038 3C013000 */  lui       $at, 0x3000
/* 4643C 8006B03C 01014824 */  and       $t1, $t0, $at
/* 46440 8006B040 00094F02 */  srl       $t1, $t1, 0x1c
/* 46444 8006B044 240A0001 */  addiu     $t2, $zero, 1
/* 46448 8006B048 152AFFC0 */  bne       $t1, $t2, panic
/* 4644C 8006B04C 00000000 */   nop      
/* 46450 8006B050 24090001 */  addiu     $t1, $zero, 1
/* 46454 8006B054 AF490018 */  sw        $t1, 0x18($k0)
/* 46458 8006B058 8F5B0118 */  lw        $k1, 0x118($k0)
/* 4645C 8006B05C 3C012000 */  lui       $at, 0x2000
/* 46460 8006B060 0361D825 */  or        $k1, $k1, $at
/* 46464 8006B064 1000FFB3 */  b         enqueueRunning
/* 46468 8006B068 AF5B0118 */   sw       $k1, 0x118($k0)
