.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025D2B0
/* 18BB90 8025D2B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 18BB94 8025D2B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 18BB98 8025D2B8 AFB10024 */  sw        $s1, 0x24($sp)
/* 18BB9C 8025D2BC AFB00020 */  sw        $s0, 0x20($sp)
/* 18BBA0 8025D2C0 8C9000C0 */  lw        $s0, 0xc0($a0)
/* 18BBA4 8025D2C4 00A0882D */  daddu     $s1, $a1, $zero
/* 18BBA8 8025D2C8 02112821 */  addu      $a1, $s0, $s1
/* 18BBAC 8025D2CC 80A308BC */  lb        $v1, 0x8bc($a1)
/* 18BBB0 8025D2D0 10600005 */  beqz      $v1, .L8025D2E8
/* 18BBB4 8025D2D4 24020001 */   addiu    $v0, $zero, 1
/* 18BBB8 8025D2D8 1062002D */  beq       $v1, $v0, .L8025D390
/* 18BBBC 8025D2DC 00111040 */   sll      $v0, $s1, 1
/* 18BBC0 8025D2E0 080974EC */  j         .L8025D3B0
/* 18BBC4 8025D2E4 00000000 */   nop      
.L8025D2E8:
/* 18BBC8 8025D2E8 C4820064 */  lwc1      $f2, 0x64($a0)
/* 18BBCC 8025D2EC 3C0142B4 */  lui       $at, 0x42b4
/* 18BBD0 8025D2F0 44810000 */  mtc1      $at, $f0
/* 18BBD4 8025D2F4 00000000 */  nop       
/* 18BBD8 8025D2F8 4602003C */  c.lt.s    $f0, $f2
/* 18BBDC 8025D2FC 00000000 */  nop       
/* 18BBE0 8025D300 45000009 */  bc1f      .L8025D328
/* 18BBE4 8025D304 24020014 */   addiu    $v0, $zero, 0x14
/* 18BBE8 8025D308 90830073 */  lbu       $v1, 0x73($a0)
/* 18BBEC 8025D30C C486005C */  lwc1      $f6, 0x5c($a0)
/* 18BBF0 8025D310 3C0140A0 */  lui       $at, 0x40a0
/* 18BBF4 8025D314 44811000 */  mtc1      $at, $f2
/* 18BBF8 8025D318 3C014234 */  lui       $at, 0x4234
/* 18BBFC 8025D31C 44812000 */  mtc1      $at, $f4
/* 18BC00 8025D320 080974D1 */  j         .L8025D344
/* 18BC04 8025D324 AFA20018 */   sw       $v0, 0x18($sp)
.L8025D328:
/* 18BC08 8025D328 90830073 */  lbu       $v1, 0x73($a0)
/* 18BC0C 8025D32C C486005C */  lwc1      $f6, 0x5c($a0)
/* 18BC10 8025D330 3C0140A0 */  lui       $at, 0x40a0
/* 18BC14 8025D334 44811000 */  mtc1      $at, $f2
/* 18BC18 8025D338 3C01C234 */  lui       $at, 0xc234
/* 18BC1C 8025D33C 44812000 */  mtc1      $at, $f4
/* 18BC20 8025D340 AFA20018 */  sw        $v0, 0x18($sp)
.L8025D344:
/* 18BC24 8025D344 44830000 */  mtc1      $v1, $f0
/* 18BC28 8025D348 00000000 */  nop       
/* 18BC2C 8025D34C 46800020 */  cvt.s.w   $f0, $f0
/* 18BC30 8025D350 46003180 */  add.s     $f6, $f6, $f0
/* 18BC34 8025D354 E7A20010 */  swc1      $f2, 0x10($sp)
/* 18BC38 8025D358 E7A40014 */  swc1      $f4, 0x14($sp)
/* 18BC3C 8025D35C 8C850058 */  lw        $a1, 0x58($a0)
/* 18BC40 8025D360 8C870060 */  lw        $a3, 0x60($a0)
/* 18BC44 8025D364 44063000 */  mfc1      $a2, $f6
/* 18BC48 8025D368 0C01C1E4 */  jal       fx_sweat
/* 18BC4C 8025D36C 0000202D */   daddu    $a0, $zero, $zero
/* 18BC50 8025D370 00111040 */  sll       $v0, $s1, 1
/* 18BC54 8025D374 02021021 */  addu      $v0, $s0, $v0
/* 18BC58 8025D378 2403000A */  addiu     $v1, $zero, 0xa
/* 18BC5C 8025D37C A44308BE */  sh        $v1, 0x8be($v0)
/* 18BC60 8025D380 02111821 */  addu      $v1, $s0, $s1
/* 18BC64 8025D384 24020001 */  addiu     $v0, $zero, 1
/* 18BC68 8025D388 080974EC */  j         .L8025D3B0
/* 18BC6C 8025D38C A06208BC */   sb       $v0, 0x8bc($v1)
.L8025D390:
/* 18BC70 8025D390 02021821 */  addu      $v1, $s0, $v0
/* 18BC74 8025D394 846208BE */  lh        $v0, 0x8be($v1)
/* 18BC78 8025D398 946408BE */  lhu       $a0, 0x8be($v1)
/* 18BC7C 8025D39C 10400003 */  beqz      $v0, .L8025D3AC
/* 18BC80 8025D3A0 2482FFFF */   addiu    $v0, $a0, -1
/* 18BC84 8025D3A4 080974EC */  j         .L8025D3B0
/* 18BC88 8025D3A8 A46208BE */   sh       $v0, 0x8be($v1)
.L8025D3AC:
/* 18BC8C 8025D3AC A0A008BC */  sb        $zero, 0x8bc($a1)
.L8025D3B0:
/* 18BC90 8025D3B0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 18BC94 8025D3B4 8FB10024 */  lw        $s1, 0x24($sp)
/* 18BC98 8025D3B8 8FB00020 */  lw        $s0, 0x20($sp)
/* 18BC9C 8025D3BC 03E00008 */  jr        $ra
/* 18BCA0 8025D3C0 27BD0030 */   addiu    $sp, $sp, 0x30
