.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BB59E0
/* BB59E0 80240000 3C018011 */  lui       $at, %hi(gPlayerStatus+0x28)
/* BB59E4 80240004 C422EFF0 */  lwc1      $f2, %lo(gPlayerStatus+0x28)($at)
/* BB59E8 80240008 3C0142C8 */  lui       $at, 0x42c8
/* BB59EC 8024000C 44810000 */  mtc1      $at, $f0
/* BB59F0 80240010 00000000 */  nop       
/* BB59F4 80240014 4600103C */  c.lt.s    $f2, $f0
/* BB59F8 80240018 00000000 */  nop       
/* BB59FC 8024001C 45010002 */  bc1t      .L80240028
/* BB5A00 80240020 0000102D */   daddu    $v0, $zero, $zero
/* BB5A04 80240024 24020002 */  addiu     $v0, $zero, 2
.L80240028:
/* BB5A08 80240028 03E00008 */  jr        $ra
/* BB5A0C 8024002C 00000000 */   nop      
