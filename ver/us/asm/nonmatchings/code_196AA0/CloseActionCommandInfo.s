.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CloseActionCommandInfo
/* 197CF0 80269410 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197CF4 80269414 10A0000D */  beqz      $a1, .L8026944C
/* 197CF8 80269418 AFBF0010 */   sw       $ra, 0x10($sp)
/* 197CFC 8026941C 3C02802A */  lui       $v0, %hi(D_8029FBE0)
/* 197D00 80269420 2442FBE0 */  addiu     $v0, $v0, %lo(D_8029FBE0)
/* 197D04 80269424 8443004A */  lh        $v1, 0x4a($v0)
/* 197D08 80269428 28620007 */  slti      $v0, $v1, 7
/* 197D0C 8026942C 10400003 */  beqz      $v0, .L8026943C
/* 197D10 80269430 28620005 */   slti     $v0, $v1, 5
/* 197D14 80269434 1040000B */  beqz      $v0, .L80269464
/* 197D18 80269438 24020002 */   addiu    $v0, $zero, 2
.L8026943C:
/* 197D1C 8026943C 0C09A327 */  jal       func_80268C9C
/* 197D20 80269440 00000000 */   nop
/* 197D24 80269444 0809A519 */  j         .L80269464
/* 197D28 80269448 0000102D */   daddu    $v0, $zero, $zero
.L8026944C:
/* 197D2C 8026944C 3C048000 */  lui       $a0, 0x8000
/* 197D30 80269450 0C05271B */  jal       sfx_stop_sound
/* 197D34 80269454 34840041 */   ori      $a0, $a0, 0x41
/* 197D38 80269458 0C093EC3 */  jal       close_action_command_instruction_popup
/* 197D3C 8026945C 00000000 */   nop
/* 197D40 80269460 24020002 */  addiu     $v0, $zero, 2
.L80269464:
/* 197D44 80269464 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197D48 80269468 03E00008 */  jr        $ra
/* 197D4C 8026946C 27BD0018 */   addiu    $sp, $sp, 0x18
