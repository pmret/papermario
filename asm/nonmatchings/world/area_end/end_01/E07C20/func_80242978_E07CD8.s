.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242978_E07CD8
/* E07CD8 80242978 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E07CDC 8024297C AFB20020 */  sw        $s2, 0x20($sp)
/* E07CE0 80242980 AFBF0024 */  sw        $ra, 0x24($sp)
/* E07CE4 80242984 AFB1001C */  sw        $s1, 0x1c($sp)
/* E07CE8 80242988 AFB00018 */  sw        $s0, 0x18($sp)
/* E07CEC 8024298C F7B40028 */  sdc1      $f20, 0x28($sp)
/* E07CF0 80242990 10A00006 */  beqz      $a1, .L802429AC
/* E07CF4 80242994 0080902D */   daddu    $s2, $a0, $zero
/* E07CF8 80242998 8E4400AC */  lw        $a0, 0xac($s2)
/* E07CFC 8024299C 0C00EAD2 */  jal       get_npc_safe
/* E07D00 802429A0 00000000 */   nop
/* E07D04 802429A4 AE420078 */  sw        $v0, 0x78($s2)
/* E07D08 802429A8 AE400070 */  sw        $zero, 0x70($s2)
.L802429AC:
/* E07D0C 802429AC 3C05444A */  lui       $a1, 0x444a
/* E07D10 802429B0 34A58000 */  ori       $a1, $a1, 0x8000
/* E07D14 802429B4 8E510078 */  lw        $s1, 0x78($s2)
/* E07D18 802429B8 4480A000 */  mtc1      $zero, $f20
/* E07D1C 802429BC 2410002D */  addiu     $s0, $zero, 0x2d
/* E07D20 802429C0 AFB00010 */  sw        $s0, 0x10($sp)
/* E07D24 802429C4 8E470070 */  lw        $a3, 0x70($s2)
/* E07D28 802429C8 4406A000 */  mfc1      $a2, $f20
/* E07D2C 802429CC 0C00A8ED */  jal       update_lerp
/* E07D30 802429D0 24040004 */   addiu    $a0, $zero, 4
/* E07D34 802429D4 4405A000 */  mfc1      $a1, $f20
/* E07D38 802429D8 3C06437F */  lui       $a2, 0x437f
/* E07D3C 802429DC E6200048 */  swc1      $f0, 0x48($s1)
/* E07D40 802429E0 AFB00010 */  sw        $s0, 0x10($sp)
/* E07D44 802429E4 8E470070 */  lw        $a3, 0x70($s2)
/* E07D48 802429E8 0C00A8ED */  jal       update_lerp
/* E07D4C 802429EC 24040004 */   addiu    $a0, $zero, 4
/* E07D50 802429F0 3C014F00 */  lui       $at, 0x4f00
/* E07D54 802429F4 44811000 */  mtc1      $at, $f2
/* E07D58 802429F8 00000000 */  nop
/* E07D5C 802429FC 4600103E */  c.le.s    $f2, $f0
/* E07D60 80242A00 00000000 */  nop
/* E07D64 80242A04 45010005 */  bc1t      .L80242A1C
/* E07D68 80242A08 263100AC */   addiu    $s1, $s1, 0xac
/* E07D6C 80242A0C 4600010D */  trunc.w.s $f4, $f0
/* E07D70 80242A10 44032000 */  mfc1      $v1, $f4
/* E07D74 80242A14 08090A8E */  j         .L80242A38
/* E07D78 80242A18 A2230000 */   sb       $v1, ($s1)
.L80242A1C:
/* E07D7C 80242A1C 46020001 */  sub.s     $f0, $f0, $f2
/* E07D80 80242A20 3C028000 */  lui       $v0, 0x8000
/* E07D84 80242A24 4600010D */  trunc.w.s $f4, $f0
/* E07D88 80242A28 44032000 */  mfc1      $v1, $f4
/* E07D8C 80242A2C 00000000 */  nop
/* E07D90 80242A30 00621825 */  or        $v1, $v1, $v0
/* E07D94 80242A34 A2230000 */  sb        $v1, ($s1)
.L80242A38:
/* E07D98 80242A38 8E430070 */  lw        $v1, 0x70($s2)
/* E07D9C 80242A3C 24630001 */  addiu     $v1, $v1, 1
/* E07DA0 80242A40 2862002E */  slti      $v0, $v1, 0x2e
/* E07DA4 80242A44 AE430070 */  sw        $v1, 0x70($s2)
/* E07DA8 80242A48 8FBF0024 */  lw        $ra, 0x24($sp)
/* E07DAC 80242A4C 8FB20020 */  lw        $s2, 0x20($sp)
/* E07DB0 80242A50 8FB1001C */  lw        $s1, 0x1c($sp)
/* E07DB4 80242A54 8FB00018 */  lw        $s0, 0x18($sp)
/* E07DB8 80242A58 D7B40028 */  ldc1      $f20, 0x28($sp)
/* E07DBC 80242A5C 38420001 */  xori      $v0, $v0, 1
/* E07DC0 80242A60 03E00008 */  jr        $ra
/* E07DC4 80242A64 27BD0030 */   addiu    $sp, $sp, 0x30
