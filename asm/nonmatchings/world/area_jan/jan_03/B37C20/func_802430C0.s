.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430C0
/* B37C90 802430C0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B37C94 802430C4 AFB10054 */  sw        $s1, 0x54($sp)
/* B37C98 802430C8 0080882D */  daddu     $s1, $a0, $zero
/* B37C9C 802430CC AFBF005C */  sw        $ra, 0x5c($sp)
/* B37CA0 802430D0 AFB20058 */  sw        $s2, 0x58($sp)
/* B37CA4 802430D4 AFB00050 */  sw        $s0, 0x50($sp)
/* B37CA8 802430D8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B37CAC 802430DC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B37CB0 802430E0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B37CB4 802430E4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B37CB8 802430E8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B37CBC 802430EC 8E30000C */  lw        $s0, 0xc($s1)
/* B37CC0 802430F0 8E050000 */  lw        $a1, ($s0)
/* B37CC4 802430F4 0C0B1EAF */  jal       get_variable
/* B37CC8 802430F8 26100004 */   addiu    $s0, $s0, 4
/* B37CCC 802430FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B37CD0 80243100 0040202D */   daddu    $a0, $v0, $zero
/* B37CD4 80243104 8E050000 */  lw        $a1, ($s0)
/* B37CD8 80243108 26100004 */  addiu     $s0, $s0, 4
/* B37CDC 8024310C 0220202D */  daddu     $a0, $s1, $zero
/* B37CE0 80243110 0C0B210B */  jal       get_float_variable
/* B37CE4 80243114 0040902D */   daddu    $s2, $v0, $zero
/* B37CE8 80243118 8E050000 */  lw        $a1, ($s0)
/* B37CEC 8024311C 26100004 */  addiu     $s0, $s0, 4
/* B37CF0 80243120 0220202D */  daddu     $a0, $s1, $zero
/* B37CF4 80243124 0C0B210B */  jal       get_float_variable
/* B37CF8 80243128 46000706 */   mov.s    $f28, $f0
/* B37CFC 8024312C 8E050000 */  lw        $a1, ($s0)
/* B37D00 80243130 26100004 */  addiu     $s0, $s0, 4
/* B37D04 80243134 0220202D */  daddu     $a0, $s1, $zero
/* B37D08 80243138 0C0B210B */  jal       get_float_variable
/* B37D0C 8024313C 46000686 */   mov.s    $f26, $f0
/* B37D10 80243140 0220202D */  daddu     $a0, $s1, $zero
/* B37D14 80243144 8E050000 */  lw        $a1, ($s0)
/* B37D18 80243148 0C0B210B */  jal       get_float_variable
/* B37D1C 8024314C 46000586 */   mov.s    $f22, $f0
/* B37D20 80243150 0240202D */  daddu     $a0, $s2, $zero
/* B37D24 80243154 0C046B4C */  jal       get_model_from_list_index
/* B37D28 80243158 46000606 */   mov.s    $f24, $f0
/* B37D2C 8024315C 0040882D */  daddu     $s1, $v0, $zero
/* B37D30 80243160 96220000 */  lhu       $v0, ($s1)
/* B37D34 80243164 30420400 */  andi      $v0, $v0, 0x400
/* B37D38 80243168 1440001E */  bnez      $v0, .L802431E4
/* B37D3C 8024316C 26300058 */   addiu    $s0, $s1, 0x58
/* B37D40 80243170 4480A000 */  mtc1      $zero, $f20
/* B37D44 80243174 4406B000 */  mfc1      $a2, $f22
/* B37D48 80243178 4405A000 */  mfc1      $a1, $f20
/* B37D4C 8024317C 4407A000 */  mfc1      $a3, $f20
/* B37D50 80243180 0C019E40 */  jal       guTranslateF
/* B37D54 80243184 0200202D */   daddu    $a0, $s0, $zero
/* B37D58 80243188 4405E000 */  mfc1      $a1, $f28
/* B37D5C 8024318C 4406D000 */  mfc1      $a2, $f26
/* B37D60 80243190 4407C000 */  mfc1      $a3, $f24
/* B37D64 80243194 0C090C14 */  jal       func_80243050
/* B37D68 80243198 27A40010 */   addiu    $a0, $sp, 0x10
/* B37D6C 8024319C 27A40010 */  addiu     $a0, $sp, 0x10
/* B37D70 802431A0 0200282D */  daddu     $a1, $s0, $zero
/* B37D74 802431A4 0C019D80 */  jal       guMtxCatF
/* B37D78 802431A8 0200302D */   daddu    $a2, $s0, $zero
/* B37D7C 802431AC 27A40010 */  addiu     $a0, $sp, 0x10
/* B37D80 802431B0 4600B587 */  neg.s     $f22, $f22
/* B37D84 802431B4 4405A000 */  mfc1      $a1, $f20
/* B37D88 802431B8 4406B000 */  mfc1      $a2, $f22
/* B37D8C 802431BC 0C019E40 */  jal       guTranslateF
/* B37D90 802431C0 00A0382D */   daddu    $a3, $a1, $zero
/* B37D94 802431C4 27A40010 */  addiu     $a0, $sp, 0x10
/* B37D98 802431C8 0200282D */  daddu     $a1, $s0, $zero
/* B37D9C 802431CC 0C019D80 */  jal       guMtxCatF
/* B37DA0 802431D0 00A0302D */   daddu    $a2, $a1, $zero
/* B37DA4 802431D4 96220000 */  lhu       $v0, ($s1)
/* B37DA8 802431D8 34421400 */  ori       $v0, $v0, 0x1400
/* B37DAC 802431DC 08090C97 */  j         .L8024325C
/* B37DB0 802431E0 A6220000 */   sh       $v0, ($s1)
.L802431E4:
/* B37DB4 802431E4 4480A000 */  mtc1      $zero, $f20
/* B37DB8 802431E8 4406B000 */  mfc1      $a2, $f22
/* B37DBC 802431EC 4405A000 */  mfc1      $a1, $f20
/* B37DC0 802431F0 4407A000 */  mfc1      $a3, $f20
/* B37DC4 802431F4 0C019E40 */  jal       guTranslateF
/* B37DC8 802431F8 27A40010 */   addiu    $a0, $sp, 0x10
/* B37DCC 802431FC 27A40010 */  addiu     $a0, $sp, 0x10
/* B37DD0 80243200 26300058 */  addiu     $s0, $s1, 0x58
/* B37DD4 80243204 0200282D */  daddu     $a1, $s0, $zero
/* B37DD8 80243208 0C019D80 */  jal       guMtxCatF
/* B37DDC 8024320C 0200302D */   daddu    $a2, $s0, $zero
/* B37DE0 80243210 4405E000 */  mfc1      $a1, $f28
/* B37DE4 80243214 4406D000 */  mfc1      $a2, $f26
/* B37DE8 80243218 4407C000 */  mfc1      $a3, $f24
/* B37DEC 8024321C 0C090C14 */  jal       func_80243050
/* B37DF0 80243220 27A40010 */   addiu    $a0, $sp, 0x10
/* B37DF4 80243224 27A40010 */  addiu     $a0, $sp, 0x10
/* B37DF8 80243228 0200282D */  daddu     $a1, $s0, $zero
/* B37DFC 8024322C 0C019D80 */  jal       guMtxCatF
/* B37E00 80243230 0200302D */   daddu    $a2, $s0, $zero
/* B37E04 80243234 27A40010 */  addiu     $a0, $sp, 0x10
/* B37E08 80243238 4600B587 */  neg.s     $f22, $f22
/* B37E0C 8024323C 4405A000 */  mfc1      $a1, $f20
/* B37E10 80243240 4406B000 */  mfc1      $a2, $f22
/* B37E14 80243244 0C019E40 */  jal       guTranslateF
/* B37E18 80243248 00A0382D */   daddu    $a3, $a1, $zero
/* B37E1C 8024324C 27A40010 */  addiu     $a0, $sp, 0x10
/* B37E20 80243250 0200282D */  daddu     $a1, $s0, $zero
/* B37E24 80243254 0C019D80 */  jal       guMtxCatF
/* B37E28 80243258 00A0302D */   daddu    $a2, $a1, $zero
.L8024325C:
/* B37E2C 8024325C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B37E30 80243260 8FB20058 */  lw        $s2, 0x58($sp)
/* B37E34 80243264 8FB10054 */  lw        $s1, 0x54($sp)
/* B37E38 80243268 8FB00050 */  lw        $s0, 0x50($sp)
/* B37E3C 8024326C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B37E40 80243270 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B37E44 80243274 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B37E48 80243278 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B37E4C 8024327C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B37E50 80243280 24020002 */  addiu     $v0, $zero, 2
/* B37E54 80243284 03E00008 */  jr        $ra
/* B37E58 80243288 27BD0088 */   addiu    $sp, $sp, 0x88
/* B37E5C 8024328C 00000000 */  nop       
