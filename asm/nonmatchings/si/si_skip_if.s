.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_skip_if
/* ED2AC 802C88FC 0000282D */  daddu     $a1, $zero, $zero
/* ED2B0 802C8900 8C840008 */  lw        $a0, 8($a0)
/* ED2B4 802C8904 3C06802E */  lui       $a2, %hi(D_802DA0A0)
/* ED2B8 802C8908 24C6A0A0 */  addiu     $a2, $a2, %lo(D_802DA0A0)
.L802C890C:
/* ED2BC 802C890C 8C820000 */  lw        $v0, ($a0)
/* ED2C0 802C8910 24840004 */  addiu     $a0, $a0, 4
/* ED2C4 802C8914 8C830000 */  lw        $v1, ($a0)
/* ED2C8 802C8918 24840004 */  addiu     $a0, $a0, 4
/* ED2CC 802C891C 00031880 */  sll       $v1, $v1, 2
/* ED2D0 802C8920 00832021 */  addu      $a0, $a0, $v1
/* ED2D4 802C8924 2443FFFF */  addiu     $v1, $v0, -1
/* ED2D8 802C8928 2C620013 */  sltiu     $v0, $v1, 0x13
/* ED2DC 802C892C 1040FFF7 */  beqz      $v0, .L802C890C
/* ED2E0 802C8930 00031080 */   sll      $v0, $v1, 2
/* ED2E4 802C8934 00461021 */  addu      $v0, $v0, $a2
/* ED2E8 802C8938 8C420000 */  lw        $v0, ($v0)
/* ED2EC 802C893C 00400008 */  jr        $v0
/* ED2F0 802C8940 00000000 */   nop      
.L802C8944:
/* ED2F4 802C8944 080B2251 */  j         .L802C8944
/* ED2F8 802C8948 00000000 */   nop      
/* ED2FC 802C894C 24A5FFFF */  addiu     $a1, $a1, -1
/* ED300 802C8950 04A1FFEE */  bgez      $a1, .L802C890C
/* ED304 802C8954 0080102D */   daddu    $v0, $a0, $zero
/* ED308 802C8958 03E00008 */  jr        $ra
/* ED30C 802C895C 00000000 */   nop      
/* ED310 802C8960 080B2243 */  j         .L802C890C
/* ED314 802C8964 24A50001 */   addiu    $a1, $a1, 1
/* ED318 802C8968 14A0FFE8 */  bnez      $a1, .L802C890C
/* ED31C 802C896C 0080102D */   daddu    $v0, $a0, $zero
/* ED320 802C8970 03E00008 */  jr        $ra
/* ED324 802C8974 00000000 */   nop      
