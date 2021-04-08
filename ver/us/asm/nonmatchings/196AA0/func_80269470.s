.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269470
/* 197D50 80269470 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197D54 80269474 14A00005 */  bnez      $a1, .L8026948C
/* 197D58 80269478 AFBF0010 */   sw       $ra, 0x10($sp)
/* 197D5C 8026947C 0C093EC3 */  jal       close_action_command_instruction_popup
/* 197D60 80269480 00000000 */   nop
/* 197D64 80269484 0809A526 */  j         .L80269498
/* 197D68 80269488 24020002 */   addiu    $v0, $zero, 2
.L8026948C:
/* 197D6C 8026948C 0C09A327 */  jal       func_80268C9C
/* 197D70 80269490 00000000 */   nop
/* 197D74 80269494 0000102D */  daddu     $v0, $zero, $zero
.L80269498:
/* 197D78 80269498 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197D7C 8026949C 03E00008 */  jr        $ra
/* 197D80 802694A0 27BD0018 */   addiu    $sp, $sp, 0x18
