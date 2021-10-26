.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osGetTime
/* 416A0 800662A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 416A4 800662A4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 416A8 800662A8 AFB40020 */  sw        $s4, 0x20($sp)
/* 416AC 800662AC AFB3001C */  sw        $s3, 0x1c($sp)
/* 416B0 800662B0 AFB20018 */  sw        $s2, 0x18($sp)
/* 416B4 800662B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 416B8 800662B8 0C01ACD8 */  jal       __osDisableInt
/* 416BC 800662BC AFB00010 */   sw       $s0, 0x10($sp)
/* 416C0 800662C0 0C019680 */  jal       osGetCount
/* 416C4 800662C4 0040A021 */   addu     $s4, $v0, $zero
/* 416C8 800662C8 3C03800A */  lui       $v1, %hi(D_8009A5C8)
/* 416CC 800662CC 8C63A5C8 */  lw        $v1, %lo(D_8009A5C8)($v1)
/* 416D0 800662D0 3C12800A */  lui       $s2, %hi(D_8009A608)
/* 416D4 800662D4 8E52A608 */  lw        $s2, %lo(D_8009A608)($s2)
/* 416D8 800662D8 3C13800A */  lui       $s3, %hi(D_8009A60C)
/* 416DC 800662DC 8E73A60C */  lw        $s3, %lo(D_8009A60C)($s3)
/* 416E0 800662E0 02802021 */  addu      $a0, $s4, $zero
/* 416E4 800662E4 0C01ACF4 */  jal       __osRestoreInt
/* 416E8 800662E8 00438023 */   subu     $s0, $v0, $v1
/* 416EC 800662EC 02008821 */  addu      $s1, $s0, $zero
/* 416F0 800662F0 00008021 */  addu      $s0, $zero, $zero
/* 416F4 800662F4 02711821 */  addu      $v1, $s3, $s1
/* 416F8 800662F8 0071202B */  sltu      $a0, $v1, $s1
/* 416FC 800662FC 02501021 */  addu      $v0, $s2, $s0
/* 41700 80066300 00441021 */  addu      $v0, $v0, $a0
/* 41704 80066304 8FBF0024 */  lw        $ra, 0x24($sp)
/* 41708 80066308 8FB40020 */  lw        $s4, 0x20($sp)
/* 4170C 8006630C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 41710 80066310 8FB20018 */  lw        $s2, 0x18($sp)
/* 41714 80066314 8FB10014 */  lw        $s1, 0x14($sp)
/* 41718 80066318 8FB00010 */  lw        $s0, 0x10($sp)
/* 4171C 8006631C 03E00008 */  jr        $ra
/* 41720 80066320 27BD0028 */   addiu    $sp, $sp, 0x28
/* 41724 80066324 00000000 */  nop
/* 41728 80066328 00000000 */  nop
/* 4172C 8006632C 00000000 */  nop
