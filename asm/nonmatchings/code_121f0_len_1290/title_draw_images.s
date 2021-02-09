.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel title_draw_images
/* 12D68 80037968 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 12D6C 8003796C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 12D70 80037970 AFBF0010 */  sw        $ra, 0x10($sp)
/* 12D74 80037974 0C00DE65 */  jal       title_draw_logo
/* 12D78 80037978 46007506 */   mov.s    $f20, $f14
/* 12D7C 8003797C 0C00DF85 */  jal       title_draw_copyright
/* 12D80 80037980 4600A306 */   mov.s    $f12, $f20
/* 12D84 80037984 8FBF0010 */  lw        $ra, 0x10($sp)
/* 12D88 80037988 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 12D8C 8003798C 03E00008 */  jr        $ra
/* 12D90 80037990 27BD0020 */   addiu    $sp, $sp, 0x20
