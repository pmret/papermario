.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_status_icon_danger
/* 23600 80048200 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 23604 80048204 00041040 */  sll       $v0, $a0, 1
/* 23608 80048208 00441021 */  addu      $v0, $v0, $a0
/* 2360C 8004820C 00021080 */  sll       $v0, $v0, 2
/* 23610 80048210 00441023 */  subu      $v0, $v0, $a0
/* 23614 80048214 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23618 80048218 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 2361C 8004821C 00021100 */  sll       $v0, $v0, 4
/* 23620 80048220 AFBF0010 */  sw        $ra, 0x10($sp)
/* 23624 80048224 00621821 */  addu      $v1, $v1, $v0
/* 23628 80048228 806200A8 */  lb        $v0, 0xa8($v1)
/* 2362C 8004822C 10400004 */  beqz      $v0, .L80048240
/* 23630 80048230 00000000 */   nop
/* 23634 80048234 8C6400AC */  lw        $a0, 0xac($v1)
/* 23638 80048238 0C05123D */  jal       free_hud_element
/* 2363C 8004823C A06000A8 */   sb       $zero, 0xa8($v1)
.L80048240:
/* 23640 80048240 8FBF0010 */  lw        $ra, 0x10($sp)
/* 23644 80048244 03E00008 */  jr        $ra
/* 23648 80048248 27BD0018 */   addiu    $sp, $sp, 0x18
