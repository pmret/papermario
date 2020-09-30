.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetZoneEnabled
/* EEC04 802CA254 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEC08 802CA258 AFB10014 */  sw        $s1, 0x14($sp)
/* EEC0C 802CA25C 0080882D */  daddu     $s1, $a0, $zero
/* EEC10 802CA260 AFBF0018 */  sw        $ra, 0x18($sp)
/* EEC14 802CA264 AFB00010 */  sw        $s0, 0x10($sp)
/* EEC18 802CA268 8E30000C */  lw        $s0, 0xc($s1)
/* EEC1C 802CA26C 8E050000 */  lw        $a1, ($s0)
/* EEC20 802CA270 0C0B1EAF */  jal       get_variable
/* EEC24 802CA274 26100004 */   addiu    $s0, $s0, 4
/* EEC28 802CA278 0220202D */  daddu     $a0, $s1, $zero
/* EEC2C 802CA27C 8E050000 */  lw        $a1, ($s0)
/* EEC30 802CA280 0C0B1EAF */  jal       get_variable
/* EEC34 802CA284 0040802D */   daddu    $s0, $v0, $zero
/* EEC38 802CA288 001018C0 */  sll       $v1, $s0, 3
/* EEC3C 802CA28C 00701823 */  subu      $v1, $v1, $s0
/* EEC40 802CA290 3C04800E */  lui       $a0, 0x800e
/* EEC44 802CA294 8C8491D4 */  lw        $a0, -0x6e2c($a0)
/* EEC48 802CA298 00031880 */  sll       $v1, $v1, 2
/* EEC4C 802CA29C 00838821 */  addu      $s1, $a0, $v1
/* EEC50 802CA2A0 86240006 */  lh        $a0, 6($s1)
/* EEC54 802CA2A4 04800003 */  bltz      $a0, .L802CA2B4
/* EEC58 802CA2A8 0040802D */   daddu    $s0, $v0, $zero
/* EEC5C 802CA2AC 0C0B286E */  jal       set_zone_enabled
/* EEC60 802CA2B0 0200282D */   daddu    $a1, $s0, $zero
.L802CA2B4:
/* EEC64 802CA2B4 12000006 */  beqz      $s0, .L802CA2D0
/* EEC68 802CA2B8 3C030001 */   lui      $v1, 1
/* EEC6C 802CA2BC 24020001 */  addiu     $v0, $zero, 1
/* EEC70 802CA2C0 12020006 */  beq       $s0, $v0, .L802CA2DC
/* EEC74 802CA2C4 3C03FFFE */   lui      $v1, 0xfffe
/* EEC78 802CA2C8 080B28BB */  j         .L802CA2EC
/* EEC7C 802CA2CC 00000000 */   nop      
.L802CA2D0:
/* EEC80 802CA2D0 8E220000 */  lw        $v0, ($s1)
/* EEC84 802CA2D4 080B28BA */  j         .L802CA2E8
/* EEC88 802CA2D8 00431025 */   or       $v0, $v0, $v1
.L802CA2DC:
/* EEC8C 802CA2DC 8E220000 */  lw        $v0, ($s1)
/* EEC90 802CA2E0 3463FFFF */  ori       $v1, $v1, 0xffff
/* EEC94 802CA2E4 00431024 */  and       $v0, $v0, $v1
.L802CA2E8:
/* EEC98 802CA2E8 AE220000 */  sw        $v0, ($s1)
.L802CA2EC:
/* EEC9C 802CA2EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EECA0 802CA2F0 8FB10014 */  lw        $s1, 0x14($sp)
/* EECA4 802CA2F4 8FB00010 */  lw        $s0, 0x10($sp)
/* EECA8 802CA2F8 24020002 */  addiu     $v0, $zero, 2
/* EECAC 802CA2FC 03E00008 */  jr        $ra
/* EECB0 802CA300 27BD0020 */   addiu    $sp, $sp, 0x20
