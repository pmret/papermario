.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_draw_bp_orbs
/* 13A798 80247458 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 13A79C 8024745C AFBF0028 */  sw        $ra, 0x28($sp)
/* 13A7A0 80247460 00A0182D */  daddu     $v1, $a1, $zero
/* 13A7A4 80247464 00C0382D */  daddu     $a3, $a2, $zero
/* 13A7A8 80247468 10800006 */  beqz      $a0, .L80247484
/* 13A7AC 8024746C 24080008 */   addiu    $t0, $zero, 8
/* 13A7B0 80247470 24020001 */  addiu     $v0, $zero, 1
/* 13A7B4 80247474 1082000B */  beq       $a0, $v0, .L802474A4
/* 13A7B8 80247478 00032080 */   sll      $a0, $v1, 2
/* 13A7BC 8024747C 08091D33 */  j         .L802474CC
/* 13A7C0 80247480 00072880 */   sll      $a1, $a3, 2
.L80247484:
/* 13A7C4 80247484 00032080 */  sll       $a0, $v1, 2
/* 13A7C8 80247488 00072880 */  sll       $a1, $a3, 2
/* 13A7CC 8024748C 24660008 */  addiu     $a2, $v1, 8
/* 13A7D0 80247490 00063080 */  sll       $a2, $a2, 2
/* 13A7D4 80247494 24E70008 */  addiu     $a3, $a3, 8
/* 13A7D8 80247498 00073880 */  sll       $a3, $a3, 2
/* 13A7DC 8024749C 08091D38 */  j         .L802474E0
/* 13A7E0 802474A0 24020100 */   addiu    $v0, $zero, 0x100
.L802474A4:
/* 13A7E4 802474A4 00072880 */  sll       $a1, $a3, 2
/* 13A7E8 802474A8 24660008 */  addiu     $a2, $v1, 8
/* 13A7EC 802474AC 00063080 */  sll       $a2, $a2, 2
/* 13A7F0 802474B0 24E70008 */  addiu     $a3, $a3, 8
/* 13A7F4 802474B4 00073880 */  sll       $a3, $a3, 2
/* 13A7F8 802474B8 24020400 */  addiu     $v0, $zero, 0x400
/* 13A7FC 802474BC AFA00010 */  sw        $zero, 0x10($sp)
/* 13A800 802474C0 AFA00014 */  sw        $zero, 0x14($sp)
/* 13A804 802474C4 08091D3C */  j         .L802474F0
/* 13A808 802474C8 AFA00018 */   sw       $zero, 0x18($sp)
.L802474CC:
/* 13A80C 802474CC 00683021 */  addu      $a2, $v1, $t0
/* 13A810 802474D0 00063080 */  sll       $a2, $a2, 2
/* 13A814 802474D4 00E83821 */  addu      $a3, $a3, $t0
/* 13A818 802474D8 00073880 */  sll       $a3, $a3, 2
/* 13A81C 802474DC 24020200 */  addiu     $v0, $zero, 0x200
.L802474E0:
/* 13A820 802474E0 AFA20018 */  sw        $v0, 0x18($sp)
/* 13A824 802474E4 24020400 */  addiu     $v0, $zero, 0x400
/* 13A828 802474E8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13A82C 802474EC AFA00014 */  sw        $zero, 0x14($sp)
.L802474F0:
/* 13A830 802474F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13A834 802474F4 0C091216 */  jal       pause_draw_rect
/* 13A838 802474F8 AFA20020 */   sw       $v0, 0x20($sp)
/* 13A83C 802474FC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 13A840 80247500 03E00008 */  jr        $ra
/* 13A844 80247504 27BD0030 */   addiu    $sp, $sp, 0x30
