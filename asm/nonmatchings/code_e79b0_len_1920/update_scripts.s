.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_scripts
/* E8724 802C3D74 3C028007 */  lui       $v0, 0x8007
/* E8728 802C3D78 8C42419C */  lw        $v0, 0x419c($v0)
/* E872C 802C3D7C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E8730 802C3D80 AFBF002C */  sw        $ra, 0x2c($sp)
/* E8734 802C3D84 AFB60028 */  sw        $s6, 0x28($sp)
/* E8738 802C3D88 AFB50024 */  sw        $s5, 0x24($sp)
/* E873C 802C3D8C AFB40020 */  sw        $s4, 0x20($sp)
/* E8740 802C3D90 AFB3001C */  sw        $s3, 0x1c($sp)
/* E8744 802C3D94 AFB20018 */  sw        $s2, 0x18($sp)
/* E8748 802C3D98 AFB10014 */  sw        $s1, 0x14($sp)
/* E874C 802C3D9C AFB00010 */  sw        $s0, 0x10($sp)
/* E8750 802C3DA0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* E8754 802C3DA4 80420078 */  lb        $v0, 0x78($v0)
/* E8758 802C3DA8 24030001 */  addiu     $v1, $zero, 1
/* E875C 802C3DAC 10430042 */  beq       $v0, $v1, .L802C3EB8
/* E8760 802C3DB0 00000000 */   nop      
/* E8764 802C3DB4 3C01802E */  lui       $at, 0x802e
/* E8768 802C3DB8 AC239CA4 */  sw        $v1, -0x635c($at)
/* E876C 802C3DBC 0C0B0C00 */  jal       sort_scripts
/* E8770 802C3DC0 0000902D */   daddu    $s2, $zero, $zero
/* E8774 802C3DC4 3C02802E */  lui       $v0, 0x802e
/* E8778 802C3DC8 8C42AC98 */  lw        $v0, -0x5368($v0)
/* E877C 802C3DCC 18400038 */  blez      $v0, .L802C3EB0
/* E8780 802C3DD0 24160001 */   addiu    $s6, $zero, 1
/* E8784 802C3DD4 3C013FF0 */  lui       $at, 0x3ff0
/* E8788 802C3DD8 4481A800 */  mtc1      $at, $f21
/* E878C 802C3DDC 4480A000 */  mtc1      $zero, $f20
/* E8790 802C3DE0 2415FFFF */  addiu     $s5, $zero, -1
/* E8794 802C3DE4 3C14802E */  lui       $s4, 0x802e
/* E8798 802C3DE8 2694AA98 */  addiu     $s4, $s4, -0x5568
/* E879C 802C3DEC 3C13802E */  lui       $s3, 0x802e
/* E87A0 802C3DF0 2673A898 */  addiu     $s3, $s3, -0x5768
.L802C3DF4:
/* E87A4 802C3DF4 8E620000 */  lw        $v0, ($s3)
/* E87A8 802C3DF8 3C03802E */  lui       $v1, 0x802e
/* E87AC 802C3DFC 8C63A890 */  lw        $v1, -0x5770($v1)
/* E87B0 802C3E00 00021080 */  sll       $v0, $v0, 2
/* E87B4 802C3E04 00431021 */  addu      $v0, $v0, $v1
/* E87B8 802C3E08 8C500000 */  lw        $s0, ($v0)
/* E87BC 802C3E0C 52000022 */  beql      $s0, $zero, .L802C3E98
/* E87C0 802C3E10 26940004 */   addiu    $s4, $s4, 4
/* E87C4 802C3E14 8E030144 */  lw        $v1, 0x144($s0)
/* E87C8 802C3E18 8E820000 */  lw        $v0, ($s4)
/* E87CC 802C3E1C 5462001E */  bnel      $v1, $v0, .L802C3E98
/* E87D0 802C3E20 26940004 */   addiu    $s4, $s4, 4
/* E87D4 802C3E24 92020000 */  lbu       $v0, ($s0)
/* E87D8 802C3E28 5040001B */  beql      $v0, $zero, .L802C3E98
/* E87DC 802C3E2C 26940004 */   addiu    $s4, $s4, 4
/* E87E0 802C3E30 30420092 */  andi      $v0, $v0, 0x92
/* E87E4 802C3E34 54400018 */  bnel      $v0, $zero, .L802C3E98
/* E87E8 802C3E38 26940004 */   addiu    $s4, $s4, 4
/* E87EC 802C3E3C C6020154 */  lwc1      $f2, 0x154($s0)
/* E87F0 802C3E40 C6000150 */  lwc1      $f0, 0x150($s0)
/* E87F4 802C3E44 46001080 */  add.s     $f2, $f2, $f0
/* E87F8 802C3E48 0000882D */  daddu     $s1, $zero, $zero
/* E87FC 802C3E4C E6020154 */  swc1      $f2, 0x154($s0)
.L802C3E50:
/* E8800 802C3E50 C6000154 */  lwc1      $f0, 0x154($s0)
/* E8804 802C3E54 46000021 */  cvt.d.s   $f0, $f0
/* E8808 802C3E58 4634003C */  c.lt.d    $f0, $f20
/* E880C 802C3E5C 00000000 */  nop       
/* E8810 802C3E60 4501000B */  bc1t      .L802C3E90
/* E8814 802C3E64 0200202D */   daddu    $a0, $s0, $zero
/* E8818 802C3E68 46340001 */  sub.d     $f0, $f0, $f20
/* E881C 802C3E6C 46200020 */  cvt.s.d   $f0, $f0
/* E8820 802C3E70 0C0B1D01 */  jal       si_execute_next_command
/* E8824 802C3E74 E6000154 */   swc1     $f0, 0x154($s0)
/* E8828 802C3E78 14560003 */  bne       $v0, $s6, .L802C3E88
/* E882C 802C3E7C 00000000 */   nop      
/* E8830 802C3E80 080B0FA4 */  j         .L802C3E90
/* E8834 802C3E84 24110001 */   addiu    $s1, $zero, 1
.L802C3E88:
/* E8838 802C3E88 1455FFF1 */  bne       $v0, $s5, .L802C3E50
/* E883C 802C3E8C 00000000 */   nop      
.L802C3E90:
/* E8840 802C3E90 16200007 */  bnez      $s1, .L802C3EB0
/* E8844 802C3E94 26940004 */   addiu    $s4, $s4, 4
.L802C3E98:
/* E8848 802C3E98 3C02802E */  lui       $v0, 0x802e
/* E884C 802C3E9C 8C42AC98 */  lw        $v0, -0x5368($v0)
/* E8850 802C3EA0 26520001 */  addiu     $s2, $s2, 1
/* E8854 802C3EA4 0242102A */  slt       $v0, $s2, $v0
/* E8858 802C3EA8 1440FFD2 */  bnez      $v0, .L802C3DF4
/* E885C 802C3EAC 26730004 */   addiu    $s3, $s3, 4
.L802C3EB0:
/* E8860 802C3EB0 3C01802E */  lui       $at, 0x802e
/* E8864 802C3EB4 AC209CA4 */  sw        $zero, -0x635c($at)
.L802C3EB8:
/* E8868 802C3EB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* E886C 802C3EBC 8FB60028 */  lw        $s6, 0x28($sp)
/* E8870 802C3EC0 8FB50024 */  lw        $s5, 0x24($sp)
/* E8874 802C3EC4 8FB40020 */  lw        $s4, 0x20($sp)
/* E8878 802C3EC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* E887C 802C3ECC 8FB20018 */  lw        $s2, 0x18($sp)
/* E8880 802C3ED0 8FB10014 */  lw        $s1, 0x14($sp)
/* E8884 802C3ED4 8FB00010 */  lw        $s0, 0x10($sp)
/* E8888 802C3ED8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* E888C 802C3EDC 03E00008 */  jr        $ra
/* E8890 802C3EE0 27BD0038 */   addiu    $sp, $sp, 0x38
