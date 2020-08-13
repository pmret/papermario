.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel load_sprite
/* 101BFC 802DEB0C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 101C00 802DEB10 AFB50024 */  sw    $s5, 0x24($sp)
/* 101C04 802DEB14 0080A82D */  daddu $s5, $a0, $zero
/* 101C08 802DEB18 AFB40020 */  sw    $s4, 0x20($sp)
/* 101C0C 802DEB1C 00A0A02D */  daddu $s4, $a1, $zero
/* 101C10 802DEB20 AFB60028 */  sw    $s6, 0x28($sp)
/* 101C14 802DEB24 00C0B02D */  daddu $s6, $a2, $zero
/* 101C18 802DEB28 AFBF002C */  sw    $ra, 0x2c($sp)
/* 101C1C 802DEB2C AFB3001C */  sw    $s3, 0x1c($sp)
/* 101C20 802DEB30 AFB20018 */  sw    $s2, 0x18($sp)
/* 101C24 802DEB34 AFB10014 */  sw    $s1, 0x14($sp)
/* 101C28 802DEB38 12800005 */  beqz  $s4, .L802DEB50
/* 101C2C 802DEB3C AFB00010 */   sw    $s0, 0x10($sp)
/* 101C30 802DEB40 3C13802E */  lui   $s3, 0x802e
/* 101C34 802DEB44 8E730C64 */  lw    $s3, 0xc64($s3)
/* 101C38 802DEB48 080B7AD7 */  j     .L802DEB5C
/* 101C3C 802DEB4C 00152080 */   sll   $a0, $s5, 2

.L802DEB50:
/* 101C40 802DEB50 3C13802E */  lui   $s3, 0x802e
/* 101C44 802DEB54 8E730C68 */  lw    $s3, 0xc68($s3)
/* 101C48 802DEB58 00152080 */  sll   $a0, $s5, 2
.L802DEB5C:
/* 101C4C 802DEB5C 02642021 */  addu  $a0, $s3, $a0
/* 101C50 802DEB60 3C11802E */  lui   $s1, 0x802e
/* 101C54 802DEB64 2631FEB0 */  addiu $s1, $s1, -0x150
/* 101C58 802DEB68 0220282D */  daddu $a1, $s1, $zero
/* 101C5C 802DEB6C 0C017D24 */  jal   nuPiReadRom
/* 101C60 802DEB70 24060008 */   addiu $a2, $zero, 8
/* 101C64 802DEB74 8E300004 */  lw    $s0, 4($s1)
/* 101C68 802DEB78 8E220000 */  lw    $v0, ($s1)
/* 101C6C 802DEB7C 02028023 */  subu  $s0, $s0, $v0
/* 101C70 802DEB80 26100007 */  addiu $s0, $s0, 7
/* 101C74 802DEB84 2402FFF8 */  addiu $v0, $zero, -8
/* 101C78 802DEB88 02028024 */  and   $s0, $s0, $v0
/* 101C7C 802DEB8C 0C00AB0A */  jal   general_heap_malloc
/* 101C80 802DEB90 0200202D */   daddu $a0, $s0, $zero
/* 101C84 802DEB94 0040902D */  daddu $s2, $v0, $zero
/* 101C88 802DEB98 0240282D */  daddu $a1, $s2, $zero
/* 101C8C 802DEB9C 8E240000 */  lw    $a0, ($s1)
/* 101C90 802DEBA0 0200302D */  daddu $a2, $s0, $zero
/* 101C94 802DEBA4 0C017D24 */  jal   nuPiReadRom
/* 101C98 802DEBA8 02642021 */   addu  $a0, $s3, $a0
/* 101C9C 802DEBAC 12C00008 */  beqz  $s6, .L802DEBD0
/* 101CA0 802DEBB0 26450004 */   addiu $a1, $s2, 4
/* 101CA4 802DEBB4 8CA50000 */  lw    $a1, ($a1)
/* 101CA8 802DEBB8 3C048035 */  lui   $a0, 0x8035
/* 101CAC 802DEBBC 2484F800 */  addiu $a0, $a0, -0x800
/* 101CB0 802DEBC0 0C00A459 */  jal   _heap_malloc_tail
/* 101CB4 802DEBC4 00000000 */   nop   
/* 101CB8 802DEBC8 080B7AFA */  j     .L802DEBE8
/* 101CBC 802DEBCC 0040882D */   daddu $s1, $v0, $zero

.L802DEBD0:
/* 101CC0 802DEBD0 8CA50000 */  lw    $a1, ($a1)
/* 101CC4 802DEBD4 3C048035 */  lui   $a0, 0x8035
/* 101CC8 802DEBD8 2484F800 */  addiu $a0, $a0, -0x800
/* 101CCC 802DEBDC 0C00A41B */  jal   _heap_malloc
/* 101CD0 802DEBE0 00000000 */   nop   
/* 101CD4 802DEBE4 0040882D */  daddu $s1, $v0, $zero
.L802DEBE8:
/* 101CD8 802DEBE8 0240202D */  daddu $a0, $s2, $zero
/* 101CDC 802DEBEC 0C01BB7C */  jal   decode_yay0
/* 101CE0 802DEBF0 0220282D */   daddu $a1, $s1, $zero
/* 101CE4 802DEBF4 0C00AB1E */  jal   general_heap_free
/* 101CE8 802DEBF8 0240202D */   daddu $a0, $s2, $zero
/* 101CEC 802DEBFC 2404FFFF */  addiu $a0, $zero, -1
/* 101CF0 802DEC00 00111082 */  srl   $v0, $s1, 2
/* 101CF4 802DEC04 8E320000 */  lw    $s2, ($s1)
/* 101CF8 802DEC08 00021080 */  sll   $v0, $v0, 2
/* 101CFC 802DEC0C 02429021 */  addu  $s2, $s2, $v0
/* 101D00 802DEC10 AE320000 */  sw    $s2, ($s1)
.L802DEC14:
/* 101D04 802DEC14 8E450000 */  lw    $a1, ($s2)
/* 101D08 802DEC18 10A40008 */  beq   $a1, $a0, .L802DEC3C
/* 101D0C 802DEC1C 00A22821 */   addu  $a1, $a1, $v0
/* 101D10 802DEC20 AE450000 */  sw    $a1, ($s2)
/* 101D14 802DEC24 8CA30000 */  lw    $v1, ($a1)
/* 101D18 802DEC28 1680FFFA */  bnez  $s4, .L802DEC14
/* 101D1C 802DEC2C 26520004 */   addiu $s2, $s2, 4
/* 101D20 802DEC30 00621821 */  addu  $v1, $v1, $v0
/* 101D24 802DEC34 080B7B05 */  j     .L802DEC14
/* 101D28 802DEC38 ACA30000 */   sw    $v1, ($a1)

.L802DEC3C:
/* 101D2C 802DEC3C 1280002D */  beqz  $s4, .L802DECF4
/* 101D30 802DEC40 00151880 */   sll   $v1, $s5, 2
/* 101D34 802DEC44 3C13802E */  lui   $s3, 0x802e
/* 101D38 802DEC48 2673FEB8 */  addiu $s3, $s3, -0x148
/* 101D3C 802DEC4C 0260282D */  daddu $a1, $s3, $zero
/* 101D40 802DEC50 24060194 */  addiu $a2, $zero, 0x194
/* 101D44 802DEC54 3C12802E */  lui   $s2, 0x802e
/* 101D48 802DEC58 2652004C */  addiu $s2, $s2, 0x4c
/* 101D4C 802DEC5C 8E420000 */  lw    $v0, ($s2)
/* 101D50 802DEC60 3C04802E */  lui   $a0, 0x802e
/* 101D54 802DEC64 24840C20 */  addiu $a0, $a0, 0xc20
/* 101D58 802DEC68 3C01802E */  lui   $at, 0x802e
/* 101D5C 802DEC6C 00230821 */  addu  $at, $at, $v1
/* 101D60 802DEC70 AC220050 */  sw    $v0, 0x50($at)
/* 101D64 802DEC74 26A20001 */  addiu $v0, $s5, 1
/* 101D68 802DEC78 00021080 */  sll   $v0, $v0, 2
/* 101D6C 802DEC7C 00441021 */  addu  $v0, $v0, $a0
/* 101D70 802DEC80 00641821 */  addu  $v1, $v1, $a0
/* 101D74 802DEC84 3C04802E */  lui   $a0, 0x802e
/* 101D78 802DEC88 8C840C60 */  lw    $a0, 0xc60($a0)
/* 101D7C 802DEC8C 3C07802E */  lui   $a3, 0x802e
/* 101D80 802DEC90 8CE70C14 */  lw    $a3, 0xc14($a3)
/* 101D84 802DEC94 8C680000 */  lw    $t0, ($v1)
/* 101D88 802DEC98 8C420000 */  lw    $v0, ($v0)
/* 101D8C 802DEC9C 00872021 */  addu  $a0, $a0, $a3
/* 101D90 802DECA0 00081880 */  sll   $v1, $t0, 2
/* 101D94 802DECA4 00832021 */  addu  $a0, $a0, $v1
/* 101D98 802DECA8 0C017D24 */  jal   nuPiReadRom
/* 101D9C 802DECAC 00488023 */   subu  $s0, $v0, $t0
/* 101DA0 802DECB0 1A000010 */  blez  $s0, .L802DECF4
/* 101DA4 802DECB4 0000302D */   daddu $a2, $zero, $zero
/* 101DA8 802DECB8 3C08802E */  lui   $t0, 0x802e
/* 101DAC 802DECBC 25080090 */  addiu $t0, $t0, 0x90
/* 101DB0 802DECC0 0240382D */  daddu $a3, $s2, $zero
/* 101DB4 802DECC4 0260282D */  daddu $a1, $s3, $zero
.L802DECC8:
/* 101DB8 802DECC8 8CA40000 */  lw    $a0, ($a1)
/* 101DBC 802DECCC 24A50004 */  addiu $a1, $a1, 4
/* 101DC0 802DECD0 8CE30000 */  lw    $v1, ($a3)
/* 101DC4 802DECD4 24C60001 */  addiu $a2, $a2, 1
/* 101DC8 802DECD8 00031080 */  sll   $v0, $v1, 2
/* 101DCC 802DECDC 24630001 */  addiu $v1, $v1, 1
/* 101DD0 802DECE0 00481021 */  addu  $v0, $v0, $t0
/* 101DD4 802DECE4 AC440000 */  sw    $a0, ($v0)
/* 101DD8 802DECE8 00D0102A */  slt   $v0, $a2, $s0
/* 101DDC 802DECEC 1440FFF6 */  bnez  $v0, .L802DECC8
/* 101DE0 802DECF0 ACE30000 */   sw    $v1, ($a3)
.L802DECF4:
/* 101DE4 802DECF4 2404FFFF */  addiu $a0, $zero, -1
/* 101DE8 802DECF8 00111082 */  srl   $v0, $s1, 2
/* 101DEC 802DECFC 8E230004 */  lw    $v1, 4($s1)
/* 101DF0 802DED00 00021080 */  sll   $v0, $v0, 2
/* 101DF4 802DED04 00621821 */  addu  $v1, $v1, $v0
/* 101DF8 802DED08 AE230004 */  sw    $v1, 4($s1)
.L802DED0C:
/* 101DFC 802DED0C 8C650000 */  lw    $a1, ($v1)
/* 101E00 802DED10 10A40004 */  beq   $a1, $a0, .L802DED24
/* 101E04 802DED14 00A22821 */   addu  $a1, $a1, $v0
/* 101E08 802DED18 AC650000 */  sw    $a1, ($v1)
/* 101E0C 802DED1C 080B7B43 */  j     .L802DED0C
/* 101E10 802DED20 24630004 */   addiu $v1, $v1, 4

.L802DED24:
/* 101E14 802DED24 0000202D */  daddu $a0, $zero, $zero
/* 101E18 802DED28 0080282D */  daddu $a1, $a0, $zero
/* 101E1C 802DED2C 0C0B7AA8 */  jal   func_802DEAA0
/* 101E20 802DED30 0220302D */   daddu $a2, $s1, $zero
/* 101E24 802DED34 0220102D */  daddu $v0, $s1, $zero
/* 101E28 802DED38 8FBF002C */  lw    $ra, 0x2c($sp)
/* 101E2C 802DED3C 8FB60028 */  lw    $s6, 0x28($sp)
/* 101E30 802DED40 8FB50024 */  lw    $s5, 0x24($sp)
/* 101E34 802DED44 8FB40020 */  lw    $s4, 0x20($sp)
/* 101E38 802DED48 8FB3001C */  lw    $s3, 0x1c($sp)
/* 101E3C 802DED4C 8FB20018 */  lw    $s2, 0x18($sp)
/* 101E40 802DED50 8FB10014 */  lw    $s1, 0x14($sp)
/* 101E44 802DED54 8FB00010 */  lw    $s0, 0x10($sp)
/* 101E48 802DED58 03E00008 */  jr    $ra
/* 101E4C 802DED5C 27BD0030 */   addiu $sp, $sp, 0x30

