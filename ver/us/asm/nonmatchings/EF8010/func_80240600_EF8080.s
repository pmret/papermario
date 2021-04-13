.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240600_EF8080
/* EF8080 80240600 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EF8084 80240604 AFB10054 */  sw        $s1, 0x54($sp)
/* EF8088 80240608 0080882D */  daddu     $s1, $a0, $zero
/* EF808C 8024060C AFBF005C */  sw        $ra, 0x5c($sp)
/* EF8090 80240610 AFB20058 */  sw        $s2, 0x58($sp)
/* EF8094 80240614 AFB00050 */  sw        $s0, 0x50($sp)
/* EF8098 80240618 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* EF809C 8024061C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EF80A0 80240620 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EF80A4 80240624 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EF80A8 80240628 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EF80AC 8024062C 8E30000C */  lw        $s0, 0xc($s1)
/* EF80B0 80240630 8E050000 */  lw        $a1, ($s0)
/* EF80B4 80240634 0C0B53A3 */  jal       dead_get_variable
/* EF80B8 80240638 26100004 */   addiu    $s0, $s0, 4
/* EF80BC 8024063C 0C04949C */  jal       func_80125270
/* EF80C0 80240640 0040202D */   daddu    $a0, $v0, $zero
/* EF80C4 80240644 8E050000 */  lw        $a1, ($s0)
/* EF80C8 80240648 26100004 */  addiu     $s0, $s0, 4
/* EF80CC 8024064C 0220202D */  daddu     $a0, $s1, $zero
/* EF80D0 80240650 0C0B55FF */  jal       dead_get_float_variable
/* EF80D4 80240654 0040902D */   daddu    $s2, $v0, $zero
/* EF80D8 80240658 8E050000 */  lw        $a1, ($s0)
/* EF80DC 8024065C 26100004 */  addiu     $s0, $s0, 4
/* EF80E0 80240660 0220202D */  daddu     $a0, $s1, $zero
/* EF80E4 80240664 0C0B55FF */  jal       dead_get_float_variable
/* EF80E8 80240668 46000706 */   mov.s    $f28, $f0
/* EF80EC 8024066C 8E050000 */  lw        $a1, ($s0)
/* EF80F0 80240670 26100004 */  addiu     $s0, $s0, 4
/* EF80F4 80240674 0220202D */  daddu     $a0, $s1, $zero
/* EF80F8 80240678 0C0B55FF */  jal       dead_get_float_variable
/* EF80FC 8024067C 46000686 */   mov.s    $f26, $f0
/* EF8100 80240680 0220202D */  daddu     $a0, $s1, $zero
/* EF8104 80240684 8E050000 */  lw        $a1, ($s0)
/* EF8108 80240688 0C0B55FF */  jal       dead_get_float_variable
/* EF810C 8024068C 46000586 */   mov.s    $f22, $f0
/* EF8110 80240690 0240202D */  daddu     $a0, $s2, $zero
/* EF8114 80240694 0C0493D1 */  jal       func_80124F44
/* EF8118 80240698 46000606 */   mov.s    $f24, $f0
/* EF811C 8024069C 0040882D */  daddu     $s1, $v0, $zero
/* EF8120 802406A0 96220000 */  lhu       $v0, ($s1)
/* EF8124 802406A4 30420400 */  andi      $v0, $v0, 0x400
/* EF8128 802406A8 1440001E */  bnez      $v0, .L80240724
/* EF812C 802406AC 26300058 */   addiu    $s0, $s1, 0x58
/* EF8130 802406B0 4480A000 */  mtc1      $zero, $f20
/* EF8134 802406B4 4406B000 */  mfc1      $a2, $f22
/* EF8138 802406B8 4405A000 */  mfc1      $a1, $f20
/* EF813C 802406BC 4407A000 */  mfc1      $a3, $f20
/* EF8140 802406C0 0C01B2B0 */  jal       func_8006CAC0
/* EF8144 802406C4 0200202D */   daddu    $a0, $s0, $zero
/* EF8148 802406C8 4405E000 */  mfc1      $a1, $f28
/* EF814C 802406CC 4406D000 */  mfc1      $a2, $f26
/* EF8150 802406D0 4407C000 */  mfc1      $a3, $f24
/* EF8154 802406D4 0C090164 */  jal       func_80240590_EF8010
/* EF8158 802406D8 27A40010 */   addiu    $a0, $sp, 0x10
/* EF815C 802406DC 27A40010 */  addiu     $a0, $sp, 0x10
/* EF8160 802406E0 0200282D */  daddu     $a1, $s0, $zero
/* EF8164 802406E4 0C01B1F0 */  jal       osSiRawReadIo
/* EF8168 802406E8 0200302D */   daddu    $a2, $s0, $zero
/* EF816C 802406EC 27A40010 */  addiu     $a0, $sp, 0x10
/* EF8170 802406F0 4600B587 */  neg.s     $f22, $f22
/* EF8174 802406F4 4405A000 */  mfc1      $a1, $f20
/* EF8178 802406F8 4406B000 */  mfc1      $a2, $f22
/* EF817C 802406FC 0C01B2B0 */  jal       func_8006CAC0
/* EF8180 80240700 00A0382D */   daddu    $a3, $a1, $zero
/* EF8184 80240704 27A40010 */  addiu     $a0, $sp, 0x10
/* EF8188 80240708 0200282D */  daddu     $a1, $s0, $zero
/* EF818C 8024070C 0C01B1F0 */  jal       osSiRawReadIo
/* EF8190 80240710 00A0302D */   daddu    $a2, $a1, $zero
/* EF8194 80240714 96220000 */  lhu       $v0, ($s1)
/* EF8198 80240718 34421400 */  ori       $v0, $v0, 0x1400
/* EF819C 8024071C 080901E7 */  j         .L8024079C
/* EF81A0 80240720 A6220000 */   sh       $v0, ($s1)
.L80240724:
/* EF81A4 80240724 4480A000 */  mtc1      $zero, $f20
/* EF81A8 80240728 4406B000 */  mfc1      $a2, $f22
/* EF81AC 8024072C 4405A000 */  mfc1      $a1, $f20
/* EF81B0 80240730 4407A000 */  mfc1      $a3, $f20
/* EF81B4 80240734 0C01B2B0 */  jal       func_8006CAC0
/* EF81B8 80240738 27A40010 */   addiu    $a0, $sp, 0x10
/* EF81BC 8024073C 27A40010 */  addiu     $a0, $sp, 0x10
/* EF81C0 80240740 26300058 */  addiu     $s0, $s1, 0x58
/* EF81C4 80240744 0200282D */  daddu     $a1, $s0, $zero
/* EF81C8 80240748 0C01B1F0 */  jal       osSiRawReadIo
/* EF81CC 8024074C 0200302D */   daddu    $a2, $s0, $zero
/* EF81D0 80240750 4405E000 */  mfc1      $a1, $f28
/* EF81D4 80240754 4406D000 */  mfc1      $a2, $f26
/* EF81D8 80240758 4407C000 */  mfc1      $a3, $f24
/* EF81DC 8024075C 0C090164 */  jal       func_80240590_EF8010
/* EF81E0 80240760 27A40010 */   addiu    $a0, $sp, 0x10
/* EF81E4 80240764 27A40010 */  addiu     $a0, $sp, 0x10
/* EF81E8 80240768 0200282D */  daddu     $a1, $s0, $zero
/* EF81EC 8024076C 0C01B1F0 */  jal       osSiRawReadIo
/* EF81F0 80240770 0200302D */   daddu    $a2, $s0, $zero
/* EF81F4 80240774 27A40010 */  addiu     $a0, $sp, 0x10
/* EF81F8 80240778 4600B587 */  neg.s     $f22, $f22
/* EF81FC 8024077C 4405A000 */  mfc1      $a1, $f20
/* EF8200 80240780 4406B000 */  mfc1      $a2, $f22
/* EF8204 80240784 0C01B2B0 */  jal       func_8006CAC0
/* EF8208 80240788 00A0382D */   daddu    $a3, $a1, $zero
/* EF820C 8024078C 27A40010 */  addiu     $a0, $sp, 0x10
/* EF8210 80240790 0200282D */  daddu     $a1, $s0, $zero
/* EF8214 80240794 0C01B1F0 */  jal       osSiRawReadIo
/* EF8218 80240798 00A0302D */   daddu    $a2, $a1, $zero
.L8024079C:
/* EF821C 8024079C 8FBF005C */  lw        $ra, 0x5c($sp)
/* EF8220 802407A0 8FB20058 */  lw        $s2, 0x58($sp)
/* EF8224 802407A4 8FB10054 */  lw        $s1, 0x54($sp)
/* EF8228 802407A8 8FB00050 */  lw        $s0, 0x50($sp)
/* EF822C 802407AC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* EF8230 802407B0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EF8234 802407B4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EF8238 802407B8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EF823C 802407BC D7B40060 */  ldc1      $f20, 0x60($sp)
/* EF8240 802407C0 24020002 */  addiu     $v0, $zero, 2
/* EF8244 802407C4 03E00008 */  jr        $ra
/* EF8248 802407C8 27BD0088 */   addiu    $sp, $sp, 0x88
/* EF824C 802407CC 00000000 */  nop
