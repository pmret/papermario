.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055BF0
/* 30FF0 80055BF0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30FF4 80055BF4 24020001 */  addiu     $v0, $zero, 1
/* 30FF8 80055BF8 AFA40010 */  sw        $a0, 0x10($sp)
/* 30FFC 80055BFC 27A40010 */  addiu     $a0, $sp, 0x10
/* 31000 80055C00 0000282D */  daddu     $a1, $zero, $zero
/* 31004 80055C04 AFBF0030 */  sw        $ra, 0x30($sp)
/* 31008 80055C08 AFA00014 */  sw        $zero, 0x14($sp)
/* 3100C 80055C0C AFA00018 */  sw        $zero, 0x18($sp)
/* 31010 80055C10 AFA0001C */  sw        $zero, 0x1c($sp)
/* 31014 80055C14 AFA00020 */  sw        $zero, 0x20($sp)
/* 31018 80055C18 0C01372E */  jal       func_8004DCB8
/* 3101C 80055C1C AFA20024 */   sw       $v0, 0x24($sp)
/* 31020 80055C20 8FBF0030 */  lw        $ra, 0x30($sp)
/* 31024 80055C24 03E00008 */  jr        $ra
/* 31028 80055C28 27BD0038 */   addiu    $sp, $sp, 0x38
