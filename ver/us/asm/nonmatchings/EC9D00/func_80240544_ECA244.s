.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_ECA244
/* ECA244 80240544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECA248 80240548 AFBF0018 */  sw        $ra, 0x18($sp)
/* ECA24C 8024054C 8C82000C */  lw        $v0, 0xc($a0)
/* ECA250 80240550 0C0B53A3 */  jal       dead_evt_get_variable
/* ECA254 80240554 8C450000 */   lw       $a1, ($v0)
/* ECA258 80240558 0C0462EC */  jal       func_80118BB0
/* ECA25C 8024055C 0040202D */   daddu    $a0, $v0, $zero
/* ECA260 80240560 3C013F80 */  lui       $at, 0x3f80
/* ECA264 80240564 44810000 */  mtc1      $at, $f0
/* ECA268 80240568 C442004C */  lwc1      $f2, 0x4c($v0)
/* ECA26C 8024056C E7A00010 */  swc1      $f0, 0x10($sp)
/* ECA270 80240570 3C014148 */  lui       $at, 0x4148
/* ECA274 80240574 44810000 */  mtc1      $at, $f0
/* ECA278 80240578 2403004B */  addiu     $v1, $zero, 0x4b
/* ECA27C 8024057C AFA30014 */  sw        $v1, 0x14($sp)
/* ECA280 80240580 46001080 */  add.s     $f2, $f2, $f0
/* ECA284 80240584 8C450048 */  lw        $a1, 0x48($v0)
/* ECA288 80240588 8C470050 */  lw        $a3, 0x50($v0)
/* ECA28C 8024058C 44061000 */  mfc1      $a2, $f2
/* ECA290 80240590 0C01D78C */  jal       func_80075E30
/* ECA294 80240594 24040004 */   addiu    $a0, $zero, 4
/* ECA298 80240598 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECA29C 8024059C 24020002 */  addiu     $v0, $zero, 2
/* ECA2A0 802405A0 03E00008 */  jr        $ra
/* ECA2A4 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
