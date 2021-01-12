.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel close_action_command_instruction_popup
/* 17E3EC 8024FB0C 3C038028 */  lui       $v1, %hi(D_802838F8)
/* 17E3F0 8024FB10 8C6338F8 */  lw        $v1, %lo(D_802838F8)($v1)
/* 17E3F4 8024FB14 10600007 */  beqz      $v1, .L8024FB34
/* 17E3F8 8024FB18 00000000 */   nop
/* 17E3FC 8024FB1C 84640012 */  lh        $a0, 0x12($v1)
/* 17E400 8024FB20 28820043 */  slti      $v0, $a0, 0x43
/* 17E404 8024FB24 10400003 */  beqz      $v0, .L8024FB34
/* 17E408 8024FB28 2882002E */   slti     $v0, $a0, 0x2e
/* 17E40C 8024FB2C 50400001 */  beql      $v0, $zero, .L8024FB34
/* 17E410 8024FB30 A4600014 */   sh       $zero, 0x14($v1)
.L8024FB34:
/* 17E414 8024FB34 03E00008 */  jr        $ra
/* 17E418 8024FB38 00000000 */   nop
