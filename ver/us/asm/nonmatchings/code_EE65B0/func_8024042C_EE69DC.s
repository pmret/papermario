.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024042C_EE69DC
/* EE69DC 8024042C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE69E0 80240430 2404FFFC */  addiu     $a0, $zero, -4
/* EE69E4 80240434 AFBF0014 */  sw        $ra, 0x14($sp)
/* EE69E8 80240438 0C00F92F */  jal       func_8003E4BC
/* EE69EC 8024043C AFB00010 */   sw       $s0, 0x10($sp)
/* EE69F0 80240440 0000202D */  daddu     $a0, $zero, $zero
/* EE69F4 80240444 3C05FD05 */  lui       $a1, 0xfd05
/* EE69F8 80240448 34A50F80 */  ori       $a1, $a1, 0xf80
/* EE69FC 8024044C 0C0B53A3 */  jal       dead_get_variable
/* EE6A00 80240450 0040802D */   daddu    $s0, $v0, $zero
/* EE6A04 80240454 AE020000 */  sw        $v0, ($s0)
/* EE6A08 80240458 8FBF0014 */  lw        $ra, 0x14($sp)
/* EE6A0C 8024045C 8FB00010 */  lw        $s0, 0x10($sp)
/* EE6A10 80240460 24020002 */  addiu     $v0, $zero, 2
/* EE6A14 80240464 03E00008 */  jr        $ra
/* EE6A18 80240468 27BD0018 */   addiu    $sp, $sp, 0x18
